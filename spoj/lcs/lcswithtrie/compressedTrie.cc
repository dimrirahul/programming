#include <iostream>
#include <algorithm>
#include <memory>
#include <map>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;
const char EOF_1 = '#';
const char EOF_2 = '$';

struct Node;
struct BranchNode;
struct LeafNode;

using NodePtr = Node*;
using BranchNodePtr = BranchNode*;
using LeafNodePtr = LeafNode*;

struct StrWrapper {
    StrWrapper(const string& str, size_t startPos, size_t length = -1) : _str(str), _startPos(startPos), _length(length) {}

    string getContent() {
        return _length != -1 ? _str.substr(_startPos, _length) : _str.substr(_startPos);
    }

    StrWrapper& operator=(const StrWrapper& other) {
        _startPos = other._startPos;
        _length = other._length;
        return *this;
    }

    const string& _str;
    size_t _startPos;
    size_t _length;
};

struct Node {
    virtual BranchNode* addLeafNode(LeafNodePtr leafNode) = 0;
    virtual vector<NodePtr> getChildren() = 0;
    virtual void printNode() = 0;
    virtual string getContent() = 0;

    BranchNodePtr getParent() { return _parent; }
    void setParent(BranchNodePtr parent) { _parent = parent; }
    Node() : _parent(NULL) {}
    virtual ~Node() {}

    size_t findPrefixLength(const string& str1, const string& str2) {
        size_t pos = 0;
        for (; pos < str1.size() && pos < str2.size() && str1[pos] == str2[pos]; pos++);
        return pos;
    }

    void doBfs() {
       queue<NodePtr> q;
       q.push(this);
       while (!q.empty()) {
           NodePtr currNode = q.front();
           q.pop();
           currNode->printNode();
           vector<NodePtr> children = currNode->getChildren();
           for (auto it : children) {
               q.push(it);
           }
       }
    }

    vector<NodePtr> findDeepestNodes() {
        size_t maxDepth = 0;
        vector<NodePtr> res;
        queue<pair<NodePtr, int>> q;
        q.push(make_pair(this, 0));
        while (!q.empty()) {
            pair<NodePtr, int> p = q.front();
            q.pop();
            if (p.second > maxDepth) {
                maxDepth = p.second;
                res.clear();
                res.push_back(p.first);
            } else if (p.second == maxDepth) {
                res.push_back(p.first);
            }
            vector<NodePtr> children = p.first->getChildren();
            for (auto it : children) {
                q.push(make_pair(it, p.second + 1));
            }
        }
        return res;
    }

    BranchNodePtr _parent;
};

struct BranchNode : public Node {
    BranchNode(const string& str, size_t startPos, size_t length) : _wrapper(StrWrapper(str, startPos, length)) {}

    BranchNodePtr addLeafNode(LeafNodePtr leafNode);
    void addBranchNode(BranchNodePtr branchNode, bool insertAbove = false);

    vector<NodePtr> getChildren() {
        vector<NodePtr> res;
        for (auto& it: _map) res.push_back(it.second.get());
        return res;
    }

    void printNode() {
        stringstream ss;
        for (auto& it: _map) ss << (char) it.first << " ";
        cout << "BRANCH NODE: name=" << _wrapper.getContent() << " has keys " << ss.str() << "\n";
    }
    void releaseNodeFromMap(NodePtr branchNode);
    void addNodeToMap(NodePtr node);

    string getContent() { return _wrapper.getContent(); }

    StrWrapper _wrapper;
    map<int, unique_ptr<Node>> _map;

};

struct LeafNode : public Node {
    LeafNode(const string& str, size_t startPos) : _wrapper(StrWrapper(str, startPos)) {}

    BranchNodePtr addLeafNode(LeafNodePtr leafNode);

    vector<NodePtr> getChildren() { return vector<NodePtr>(); }

    void printNode() {
        cout << "LEAF NODE: " << _wrapper.getContent() << "\n";
    }

    string getContent() { return  _wrapper.getContent(); }

    StrWrapper _wrapper;
};

BranchNodePtr LeafNode::addLeafNode(LeafNodePtr leafNode) {
    size_t prefixLength = findPrefixLength(leafNode->getContent(), getContent());
    BranchNodePtr branchNodePtr = new BranchNode(_wrapper._str, _wrapper._startPos, prefixLength);
    branchNodePtr->addLeafNode(leafNode);
    branchNodePtr->addLeafNode(this);
    return branchNodePtr;
}

void BranchNode::addNodeToMap(NodePtr node) {
    int key = node->getContent()[getContent().size()];
    node->setParent(this);
    auto it = _map.find(key);
    if (it == _map.end()) {
        _map.emplace(make_pair(key, move(unique_ptr<Node>(node))));
    } else {
        //cout << "ERROR: tyring to add BranchNode : " << node->getContent() << " but we already have an entry this should not happen ";
    }
}

void BranchNode::releaseNodeFromMap(NodePtr node) {
    int key = node->getContent()[getContent().size()];
    auto it = _map.find(key);
    if (it != _map.end()) {
        it->second.release();
        _map.erase(it);
    } else {
        //cout << "ERROR: trying to release node: " << node->getContent() << " but we do not have an entry this should not happen ";
    }
}


void BranchNode::addBranchNode(BranchNodePtr branchNode, bool insertAbove) {
    if (insertAbove) { //case when we add a new parent branch node.
        setParent(branchNode->getParent());
        addNodeToMap(branchNode);
        if (getParent()) {
            getParent()->releaseNodeFromMap(branchNode);
            getParent()->addNodeToMap(this);
        }
    } else { //Add a node under this.
        if (_map.empty()) {
            //consume this branch node;
            _wrapper = branchNode->_wrapper;
            for (auto& it : branchNode->_map) {
                NodePtr node = it.second.get();
                it.second.release();
                addNodeToMap(node);
            }
            delete branchNode;
        } else {
            addNodeToMap(branchNode);
        }
    }
}

BranchNodePtr BranchNode::addLeafNode(LeafNodePtr leafNode) {
    const string prefix = getContent();
    size_t prefixLength = findPrefixLength(leafNode->getContent(), prefix);
    if (prefixLength < prefix.size()) {
        BranchNodePtr newBranchNode = new BranchNode(_wrapper._str, _wrapper._startPos, prefixLength);
        newBranchNode->addLeafNode(leafNode);
        newBranchNode->addBranchNode(this, true);
        return newBranchNode;
    }
    int key = leafNode->getContent()[prefix.size()];
    auto it = _map.find(key);
    if (it == _map.end()) {
        leafNode->setParent(this);
        _map.emplace(make_pair(key, move(unique_ptr<Node>(leafNode))));
        return this;
    }
    NodePtr currNode = it->second.get();
    releaseNodeFromMap(currNode);
    BranchNodePtr branchNode = currNode->addLeafNode(leafNode);
    addBranchNode(branchNode);
    return this;
}

int main(int argc, char **argv) {
    string s1, s2;
    cin >> s1 >> s2;
    s1 += EOF_1;
    s1 += s2;
    s1 += EOF_2;

    BranchNodePtr root = new BranchNode(s1, 0, 0);
    for (size_t pos = 0; pos < s1.size(); pos++) {
        LeafNodePtr leafNode = new LeafNode(s1, pos);
        root = root->addLeafNode(leafNode);
        //cout << "After adding node: " << pos + 1 << "\n";
        //root->doBfs();
    }
    vector<NodePtr> deepestNodes = root->findDeepestNodes();
    //cout << " DEEPEST NODES: \n";
    string longest;
    for (auto it : deepestNodes) {
        NodePtr parent = it->getParent();
        if (parent)  {
            string currStr = parent->getContent();
            if (currStr.size() > longest.size()) {
                longest = currStr;
            }
        }
        //it->printNode();
    }
    //cout << "Longest STR: " << longest;
    cout << longest.size() << "\n";
    delete root;
    return 0;
}
