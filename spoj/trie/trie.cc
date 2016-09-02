#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <sstream>


using namespace std;

struct Node;
struct BranchNode;
struct LeafNode;

using ScopedNode = unique_ptr<Node>;
using ScopedLeafNode = unique_ptr<LeafNode>;
using ScopedBranchNode = unique_ptr<BranchNode>;

using NodePtr = Node*;
using LeafNodePtr = LeafNode*;
using BranchNodePtr = BranchNode*;

struct Node {
    virtual void insertNode(LeafNodePtr leafNodePtr) = 0;
    virtual NodePtr combine(LeafNodePtr leafNodePtr, int pos) = 0;
    virtual const string* getContent() = 0;
    virtual void printNode() = 0;
    virtual vector<NodePtr> getChildren() = 0;
    virtual ~Node() {}
    virtual void doBfs() {
        queue<NodePtr> q;
        set<NodePtr> visited;
        q.push(this);
        while (!q.empty()) {
            NodePtr curr = q.front();
            q.pop();
            if (visited.count(curr)) {
                cout << "Skipping node cause it is visited\n";
                continue;
            }
            visited.insert(curr);
            curr->printNode();
            vector<NodePtr> children = curr->getChildren();
            for (auto it : children) {
                cout << "Adding children: " << it << "\n";
                q.push(it);
            }
        }
    }
};

struct LeafNode: public Node {
    LeafNode(const string s) : _content(s) {}
    virtual void insertNode(LeafNodePtr leafNodePtr) {}

    virtual const string* getContent() { return &_content; }

    virtual NodePtr combine(LeafNodePtr node, int pos) {
        BranchNodePtr branchNode = new BranchNode();
        branchNode->insertNode(node, pos+1);
        branchNode->insertNode(this, pos+1);
        return branchNode;
    }

    virtual void printNode() {
        cout << " Visiting LEAF NODE: with content = " << _content << "\n";
    }

    virtual vector<NodePtr> getChildren() {
        return vector<NodePtr>();
    }

    virtual ~LeafNode() {
        cout << "Deleting leaf node with content: " << _content << "\n";
    }

    string _content;
};

struct BranchNode: public Node {

    virtual void insertNode(LeafNodePtr node) {
        insertNode(node, 0);
    }

    void insertNode(LeafNodePtr leafNodePtr, int pos) {
        if (!leafNodePtr) {
            cout << "Trying to add null leaf node returning early\n";
            return;
        }

        if (!leafNodePtr->getContent()) {
            cout << "Leaf node has no content returning early\n";
            return;
        }

        const string* contentPtr = leafNodePtr->getContent();
        const string& content = *contentPtr;

        if (content.empty()) {
            cout << "Leaf node has no content returning early\n";
            return;
        }

        if (pos >= content.size()) {
            cout << "Invalid access for string: " << content << " at pos = " << pos << "\n";
            return;
        }

        int key = content[pos] - '0';
        auto it = _map.find(key);
        if (it == _map.end()) {
            _map.emplace(make_pair(key, move(ScopedNode(leafNodePtr))));
        } else {
            Node *curr = it->second.get();
            it->second.release();
            _map.erase(it);
            NodePtr combined = curr->combine(leafNodePtr, pos);
            _map.emplace(make_pair(key, ScopedNode(combined)));
        }
    }

    virtual const string* getContent() { return NULL; }

    virtual NodePtr combine(LeafNodePtr leafNodePtr, int pos) {
        insertNode(leafNodePtr, pos+1);
        return this;
    }

    string getKeysForNode() {
        stringstream ss;
        ss << "Node has keys for: ";
        for (auto &it : _map) {
            ss << it.first;
            ss << ", ";
        }
        return ss.str();
    }

    virtual void printNode() {
        cout << " Visiting BRANCH NODE: " << getKeysForNode() << "\n";
    }
    virtual vector<NodePtr> getChildren() {
        vector<NodePtr> ret;
        for (auto &it : _map) {
            ret.push_back(it.second.get());
        }
        return ret;
    }
    virtual ~BranchNode() {
        cout << "Deleting Branchnode: " << getKeysForNode() << "\n";
    }

    map<int, ScopedNode> _map;

};

struct CompressedBranchNode : public BranchNode {
};
int main(int argc, char **argv) {
//    int n;
    string s;
    ScopedNode root(new BranchNode());
    cin >> s;

    for (size_t pos = 0; pos < s.size(); pos++) {
        string s1 = s.substr(pos);;
        LeafNodePtr leaf = new LeafNode(s1);
        root->insertNode(leaf);
    }
    root->doBfs();
    return 0;
}

