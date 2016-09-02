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

using NodePtr = Node*;
using LeafNodePtr = LeafNode*;
using BranchNodePtr = BranchNode*;

using uniqueNodePtr = unique_ptr<Node>;
string inputString;

char terminator1 = '#';
char terminator2 = '$';
const bool dbg = true;

struct Node {
    virtual void insertNode(LeafNodePtr leafNode) = 0;
    virtual void printNode() = 0;
    virtual NodePtr combineNode(LeafNodePtr leafNode) = 0;
    virtual string getContent() {
        return string();
    }

};

struct LeafNode : public Node {
    LeafNode(const String& str, size_t pos): _pos(pos), _str(str){};

    string& _str;
    size_t _pos;

    virtual void printNode() {
        cout << "LEAF NODE: " << _str.substr(pos) << "\n";
    }

    virtual int getKey(size_t pos) {
        pos += _pos;
        if (pos >= _str.size()) {
            cout << "ERROR: trying to ask for key at pos: " << pos << " in string : " << _str << "\n";
            return -1;
        }
        return _str[pos];
    }

    virtual void insertNode(LeafNodePtr leafNode) {}

    virtual NodePtr combineNode(LeafNodePtr leafNode, int startPos) {
        NodePtr branchNode = new BranchNode();
        branchNode->combineTwoLeafNodes(leafNode, this, startPos);
        return branchNode;
    }
    virtual string getContent() {
        return _str.substr(_pos);;
    }
};

struct BranchNode : public Node {
    BranchNode() : _offset(0) {}
    virtual void insertNode(LeafNodePtr leafNode) {
        insertNode(leafNode, 0);
    }

    virtual void printNode() = 0;
    virtual NodePtr combineNode(LeafNodePtr leafNode) = 0;

    virtual void insertNode(LeafNodePtr leafNode, size_t pos) {
        int key = leafNode->getKey(pos);
        if (key == -1) delete leafNode;

        auto it = _children.find(key);
        if (it == _children.end()) {
            _children.emplace(make_pair(key, move(uniqueNodePtr(leafNode))));
        } else {
            NodePtr node = it->second.get();
            it->second.release();
            _children.erase(it);

            NodePtr combined = node->combineNode(leafNode);
            _children.emplace(make_pair(key, move(uniqueNodePtr(combined))));
        }
    }

    virtual NodePtr combineTwoLeafNodes(LeafNodePtr ptr1, LeafNodePtr ptr2, startPos) {
        _offset = startPos;
        string content1 = ptr1->getContent();
        string content2 = ptr2->getContent();
        for (size_t pos = 0; pos < min(content1.size(), content2.size()); pos++) {
            if (content1[pos] == content2[pos]) {
                _offset++;
            }
        }

    }


    int _offset;
    map <int, uniqueNodePtr> _children;
};

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;

    s1 += terminator1;
    s2 += terminator2;

    inputString += s1;
    inputString += s2;

    uniqueNodePtr root = new BranchNode();
    for (size_t pos = 0; pos < inputString.size(); pos++) {
        LeafNodePtr leafNode = new LeafNode(inputString, pos);
        root->insertNode(leafNode);
    }
    vector<string> deepestPair = root->getDeepestPair();
    if (deepestPair.size() != 2) {
        cout << "ERROR: deepest pair does not have size as 2, it is " << deepestPair.size() << "\n";
    }

    stringstream ss;
    for (size_t pos = 0; pos < min(deepestPair[0].size(), deepestPair[1].size()); pos++) {
        if (deepestPair[0][pos] == deepestPair[1][pos]) {
            ss << deepestPair[0][pos];
        } else {
            break;
        }
    }
    if (dbg) {
        cout << "Longest Substring: " << ss.str() << "\n";
    }
    cout << ss.str().size() << "\n";
    return 0;
}







