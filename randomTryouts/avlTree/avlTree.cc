#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>


using namespace std;
const int BALANCED = 1;
const int LEFT_LEFT = 2;
const int LEFT_RIGHT = 3;
const int RIGHT_RIGHT = 4;
const int RIGHT_LEFT = 5;
const int INVALID_KEY = -1;

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
            height = 0;
        }

        Node() {
            key = INVALID_KEY;
            parent = left = right = NULL;
            height = 0;
        }

        static NodePtr getNewNode(int key) {
            return NodePtr(new Node(key));
        }

        void update() {
            height = max(getHeightLeft(), getHeightRight()) + 1;
        }

        int getHeightLeft() {
            return left == NULL ? -1: left->height;
        }

        int getHeightRight() {
            return right == NULL ? -1: right->height;
        }

        int getBalance() {
            return getHeightLeft() - getHeightRight();
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
            while(t != NULL) {
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
            if (v == BALANCED) return p;
            if (v == RIGHT_RIGHT) return balanceRightRight(p);
            if (v == RIGHT_LEFT) return balanceRightLeft(p);
            if (v == LEFT_LEFT) return balanceLeftLeft(p);
            return balanceLeftRight(p);
        }

        NodePtr rotateLeft(NodePtr node) {
            NodePtr right = node->right;
            right->parent = node->parent;
            node->right = right->left;
            right->left = node;

            node->parent = right;
            if (node->left != NULL) {
                node->left->parent = node;
            }
            return right;
        }

        NodePtr rotateRight(NodePtr node) {
            NodePtr left = node->left;
            left->parent = node->parent;
            left->right = node->left;
            left->right = node;

            node->parent = left;
            if (node->left) {
                node->left->parent =  node;
            }
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

};

AvlTree avlTree;
int main(int argc, char **Argv) {

}

