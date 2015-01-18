#ifndef __BINARY_TREE_H_
#define __BINARY_TREE_H_


#include <iostream>
#include <cstdio>
#include <vector>
#include <memory>
#include <queue>

using namespace std;
class Node;
typedef shared_ptr<Node> NodePtr;
class Node {
    public:
        int value;
        NodePtr left, right;

        Node() {
            value = 0;
            left = right = NULL;
        }

        Node(int v) {
            value = v;
            left = right = NULL;
        }
};

class BinaryTreeBase {
    private:
        NodePtr getNode(int v = 0) {
            return NodePtr(new Node(v));
        }

    public:
        NodePtr root;

        void addNode(int value) {
            NodePtr node = getNode(value);
            if (root == NULL) root = node;
            else {
                NodePtr prev = root;
                NodePtr next = (prev->value >= value) ? prev->left : prev->right;

                while (next != NULL) {
                    prev = next;
                    next = (prev->value >= value) ? prev->left : prev->right;
                }

                if (value < prev->value) {
                    prev->left = node;
                } else {
                    prev->right = node;
                }
            }
        }

        BinaryTreeBase() {
            root = NULL;
        }

        void printInorder() {
            printInorder(root);
        }

        void printInorder(NodePtr root) {
            if (root == NULL) return;
            printInorder(root->left);
            printf("%d\n", root->value);
            printInorder(root->right);
        }

        void printReverseInorder() {
            printReverseInorder(root);
        }

        void printReverseInorder(NodePtr temp) {
            if (!temp) return;
            printReverseInorder(temp->right);
            printf("%d\n", temp->value);
            printReverseInorder(temp->left);
        }

        void printLevelOrder() {
            queue< pair<NodePtr, int> > q;
            q.push(make_pair(root, 0));
            int printLevel = 0;
            while (!q.empty()) {
                pair<NodePtr, int> p = q.front();
                q.pop();
                if (p.second != printLevel) {
                    printLevel++;
                    printf("\n");
                }
                printf("%d ", p.first->value);
                if (p.first->left) q.push(make_pair(p.first->left, p.second+1));
                if (p.first->right) q.push(make_pair(p.first->right, p.second+1));
            }
        }

        void getParent(NodePtr fakeRoot, int n1, vector<NodePtr>& parents) {
            if (fakeRoot->value == n1) return;
            parents.push_back(fakeRoot);
            getParent((n1 < fakeRoot->value) ? fakeRoot->left: fakeRoot->right, n1, parents);
        }
        void printCommonAncestor(int n1, int n2) {
            vector<NodePtr> n1Parents, n2Parents;
            getParent(root, n1, n1Parents);
            getParent(root, n2, n2Parents);
            int pos = 0;
            for (int i = 0; i < min(n1Parents.size(), n2Parents.size()); i++) {
                if (n1Parents[i]->value != n2Parents[i]->value) {
                    break;
                } else {
                    pos = i;
                }
            }

            printf("Common Parent = %d\n", n1Parents[pos]->value);
            
        }
};


#endif //__BINARY_TREE_H_
