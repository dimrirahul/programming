// Definition for a binary tree node.
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

using VI = vector<int>;
struct TreeNode;
struct HashedIntVector;
using HvByTreeNode = map<TreeNode*, HashedIntVector>;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
struct HashedIntVector {
    void addTreeNode(const TreeNode* node) {
        store.push_back(node->val);
    }

    void finalize() {
        for (auto it: store) {
            hashVal ^= hash<uint32_t>()(it);
        }
    }
    HashedIntVector() : hashVal(0) {
    }

    bool operator==(const HashedIntVector& o) {
        if (this == &o) return true;
        if (hashVal != o.hashVal) return false;
        return store == o.store;
    }
    void addLeftNode(const HashedIntVector& leftChildHashes) {
        addNodes(leftChildHashes, true);
    }

    void addRightNode(const HashedIntVector& rightChildHashes) {
        addNodes(rightChildHashes, false);
    }

    void addNodes(const HashedIntVector& other, bool goesBefore) {
        store.reserve(store.size() + other.store.size());
        if (goesBefore) {
            store.insert(store.begin(), other.store.begin(), other.store.end());
        } else {
            store.insert(store.end(), other.store.begin(), other.store.end());
        }
        hashVal ^= other.hashVal;

    }

    VI store;
    TreeNode* treeNode;
    size_t hashVal;
};

struct TreeNodeCmp {
    bool operator()(TreeNode* p1, TreeNode* p2) {
        return p1 < p2;
    }
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        calculateHashes(root);
        populateHivByHash();
        return serializeResultSet();
    }

    void populateHivByHash() {
        for (auto it = hvByTreeNode.begin(); it != hvByTreeNode.end(); it++) {
            auto& hiv = it->second;
            auto iterToVector = hivByHash.find(hiv.hashVal);
            if (iterToVector == hivByHash.end()) { //hiv does not have a vector.
                vector<HashedIntVector> v;
                v.push_back(hiv);
                hivByHash.insert(make_pair(hiv.hashVal, v));
            } else { //hiv has a vector.
                bool found = false;
                vector<HashedIntVector>& possibleMatches = iterToVector->second;
                for (auto& it : possibleMatches) {
                    if (it.store == hiv.store) {
                        found = true;
                        resultSet.insert(it.treeNode);
                        break;
                    }
                }
                if (!found) {
                    possibleMatches.push_back(hiv);
                }
            }
        }
    }
    vector<TreeNode*> serializeResultSet() const {
        vector<TreeNode*> res;
        for(auto it = resultSet.begin(); it != resultSet.end(); ++it) {
            res.push_back(*it);
        }
        return res;
    }
    void calculateHashes(TreeNode* root) {
        if (!root) return;
        HashedIntVector hiv;
        hiv.treeNode = root;
        hiv.addTreeNode(root);
        hiv.finalize();
        if (root->left) {
            calculateHashes(root->left);
            auto it = hvByTreeNode.find(root->left);
            hiv.addLeftNode(it->second);
        }

        if (root->right) {
            calculateHashes(root->right);
            auto it = hvByTreeNode.find(root->right);
            hiv.addRightNode(it->second);
        }
        hvByTreeNode.insert(make_pair(root, hiv));
    }

    HvByTreeNode hvByTreeNode;
    map<size_t, vector<HashedIntVector>> hivByHash;
    set<TreeNode*, TreeNodeCmp> resultSet;

};

int main() {
    return 0;
}
