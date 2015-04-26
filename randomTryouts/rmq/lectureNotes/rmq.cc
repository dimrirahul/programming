#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;
class Node;
typedef shared_ptr<Node> NodePtr;
class Node : public enable_shared_from_this<Node> {
    public:
        int v;
        NodePtr l, r, p;
        Node() { l = r = p = NULL;}
        Node(int _v) {
            v = _v;
            l = r = p = NULL;
        }
        void addChild(NodePtr other, bool isLeft) {
            other->p = shared_from_this(); 
            if (isLeft) l = other;
            else r = other;
        }
};
class SparseTable {
    public:
        NodePtr root, end;

        NodePtr getNode(int value) {
            NodePtr n(new Node(value));
            return n;
        }

        void buildTree(vector<int>& v) {
            root = end = NULL;
            for (int i = 0; i < v.size(); i++) {
                printTree(root);
                cout << "\n";
                NodePtr node = getNode(v[i]);
                if (root == NULL) {
                    end = root = node;
                    continue;
                }
                if (node->v >= end->v) {
                    if (end->l == NULL) {
                        end->addChild(node, true);
                    } else {
                        if (end->r == NULL) {
                            end->addChild(node, false);
                        } else {
                            node->addChild(end->r, true);
                            end->addChild(node, false);
                        }
                        end = node;
                    }
                } else {
                    NodePtr curr = end;
                    do {
                        curr = curr->p;
                    } while (curr != NULL && curr->v > node->v);
                    if (curr == NULL) {
                        node->addChild(root, true);
                        root = end = node;
                    } else {
                        node->addChild(curr->r, true);
                        curr->addChild(node, false);
                        end = node;
                    }
                }
            }
        }

        void printTree(NodePtr curr) {
            if (curr == NULL) return;
            cout << curr->v << " ";
            printTree(curr->l);
            printTree(curr->r);
        }

        NodePtr getRoot() { return root; }
};

vector<int> getInput() {
    vector <int> res;
    int t;
    while (cin >> t) res.push_back(t);
    return res;
}
SparseTable rmq;

int main(int argc, char **argv) {
    vector<int> v = getInput();
    rmq.buildTree(v);
    rmq.printTree(rmq.getRoot());
    return 0;
}
