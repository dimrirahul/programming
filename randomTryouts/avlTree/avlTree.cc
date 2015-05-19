#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;
const int BALANCED = 1;
const int LEFT_LEFT = 2;
const int LEFT_RIGHT = 3;
const int RIGHT_RIGHT = 4;
const int RIGHT_LEFT = 5;
const int INVALID_KEY = -1;

const int LEFT_CHILD = 6;
const int RIGHT_CHILD = 7;
const int NO_PARENT = 8;

class Node;
typedef shared_ptr<Node> NodePtr;

class Node {
    public:
        NodePtr parent, left, right;
        int key;
        int height;
        Node(int _key) {
            key = _key;
            parent = left = right = NULL;
            height = 1;
        }

        Node() {
            key = INVALID_KEY;
            parent = left = right = NULL;
            height = 1;
        }

        static NodePtr getNewNode(int key) {
            return NodePtr(new Node(key));
        }

        void update() {
            height = max(getHeightLeft(), getHeightRight()) + 1;
        }

        int getHeightLeft() {
            return left == NULL ? 0: left->height;
        }

        int getHeightRight() {
            return right == NULL ? 0: right->height;
        }

        int getBalance() {
            return getHeightLeft() - getHeightRight();
        }

        void print() {
            printf("[key=%d, height=%d, balance=%d]\t", key, height, getBalance());
        }

};

class AvlTree {
    public:
        NodePtr root;
        NodePtr insert(int key) {
            NodePtr node = Node::getNewNode(key);
            if (root == NULL) {
                root = node;
                return root;
            }
            NodePtr t = root;
            NodePtr p = NULL;
            while (t != NULL) {
                p = t;
                if (key <= t->key) {
                    t = t->left;
                } else {
                    t = t->right;
                }
            }
            if (key <= p->key) {
                p->left = node;
            } else {
                p->right = node;
            }
            node->parent = p;
            while (p != NULL) {
                p = balance(p);
                root = p;
                p = p->parent;
            }
            return root;
        }

        int getBalanceType(NodePtr p) {
            int v = p->getHeightLeft() - p->getHeightRight();
            if (abs(v) <= 1) return BALANCED;
            if (v < 0) {
                if (p->right->getBalance() < 0) return RIGHT_RIGHT;
                else return RIGHT_LEFT;
            } else {
                if (p->left->getBalance() > 0) return LEFT_LEFT;
                else return LEFT_RIGHT;
            }
        } 

        NodePtr balance(NodePtr p) {
            int v = getBalanceType(p);
            if (v == RIGHT_RIGHT) { p = balanceRightRight(p);}
            if (v == RIGHT_LEFT) { p = balanceRightLeft(p);}
            if (v == LEFT_LEFT) { p = balanceLeftLeft(p);}
            if (v == LEFT_RIGHT) { p = balanceLeftRight(p);}
            p->update();
            return p;
        }

        int isLeftOrRight(NodePtr node) {
            NodePtr parent = node->parent;
            int res = NO_PARENT;
            if (parent != NULL && parent->left == node) {
                res = LEFT_CHILD;
            } else if (parent != NULL && parent->right == node) {
                res = RIGHT_CHILD;
            }
            return res;
        }
            

        NodePtr rotateLeft(NodePtr node) {
            int childType = isLeftOrRight(node);
            NodePtr right = node->right;
            right->parent = node->parent;
            node->right = right->left;
            right->left = node;
            if (childType == LEFT_CHILD) {
                right->parent->left =  right;
            } else if (childType == RIGHT_CHILD) {
                right->parent->right = right;
            }

            node->parent = right;
            if (node->right != NULL) {
                node->right->parent = node;
            }
            node->update();
            right->update();
            return right;
        }

        NodePtr rotateRight(NodePtr node) {
            int childType = isLeftOrRight(node);
            NodePtr left = node->left;
            left->parent = node->parent;
            node->left = left->right;
            left->right = node;
            if (childType == LEFT_CHILD) {
                left->parent->left =  left;
            } else if (childType == RIGHT_CHILD) {
                left->parent->right = left;
            }

            node->parent = left;
            if (node->left != NULL) {
                node->left->parent =  node;
            }
            node->update();
            left->update();
            return left;
        }

        NodePtr balanceRightRight(NodePtr p) {
            return rotateLeft(p);
        }

        NodePtr balanceLeftLeft(NodePtr p) {
            return rotateRight(p);
        }

        NodePtr balanceRightLeft(NodePtr p) {
            p->right = rotateRight(p->right);
            return rotateLeft(p);
        }

        NodePtr balanceLeftRight(NodePtr p) {
            p->left = rotateLeft(p->left);
            return rotateRight(p);
        }

        void printInorder() {
            printInorder(root);
        }

        void printInorder(NodePtr p) {
            if (p != NULL) {
                p->print();
                printInorder(p->left);
                printInorder(p->right);
            }
        }


};

AvlTree avlTree;
int main(int argc, char **Argv) {
    vector<int> v;
    v.push_back(50);
    v.push_back(30);
    v.push_back(45);
    v.push_back(47);
    for (int i = 1; i < 65; i++) {
        avlTree.insert(i);
        cout << "\n";
        avlTree.printInorder();
    }
    return 0;
}

