#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>


using namespace std;

const int MAX_KEY = INT_MAX;
const int MAX_SZ = 50000;
typedef vector <int> VI;
class Node;
typedef shared_ptr <Node> NodePtr;
class Node {
    public:

        static NodePtr getNode(int key) {
            return NodePtr(new Node(key));
        }

        NodePtr left, right, parent;
        int key;
        Node(int _key) {
            left = right = parent = NULL;
            key = _key;
        }

        void printNode() {
            printf("[key=%d, parent=%d] ", key, parent != NULL ? parent->key: -1);
        }

};
class Heap {
    public:
        NodePtr root;
        int totNodes;
        Heap() {
            root = NULL;
            totNodes = 0;
        }

        vector<int> getPathVector(int id) {
            vector<int> dir;
            id /= 2;
            while ( id != 1 ) {
                if (id %2 ==0) {
                    dir.push_back(0);
                } else {
                    dir.push_back(1);
                }
                id /= 2;
            }
            return dir;
        }

        NodePtr findParentNode(int id) {
            cout << "Trying to find parent of id = " << id << "\n";
            NodePtr p = root;
            vector<int> dir = getPathVector(id);
            for (int i = dir.size() - 1; i >= 0; i--) {
                if (dir[i] == 0) p = p->left;
                else p = p->right;
            }
            p->printNode();
            cout  << "\n";
            return p;
        }

        NodePtr insert(int key) {
            NodePtr node = Node::getNode(key);
            if (root == NULL) {
                root = node;
                totNodes++;
                return root;
            }
            NodePtr parent = findParentNode(totNodes + 1);       
            if (parent->left == NULL) {
                parent->left = node;
            } else {
                parent->right = node;
            }
            node->parent = parent;
            heapify(node, true);
            totNodes++;
            return root;
        }

        void heapify(NodePtr node, bool add) {
            if (node->parent == NULL) return;
            if (node->parent->key > node->key) {
                swap(node->parent->key, node->key);
                heapify(node->parent, add);
            }
        }

        void printHeap() {
            printInorder(root);
        }

        void printInorder(NodePtr p) {
            if (p) {
                p->printNode();
                printInorder(p->left);
                printInorder(p->right);
            }
        }

        void printLevelOrder() {
            if (root == NULL) return;
            queue <pair < NodePtr, int> > dq;
            dq.push(make_pair(root, 0));
            int prevLevel = -1;
            while (!dq.empty()) {
                pair <NodePtr, int> p = dq.front();
                NodePtr f = p.first;
                if (prevLevel != p.second) {
                    prevLevel = p.second;
                    cout << "\n";
                }
                f->printNode();
                dq.pop();
                if (f->left) {
                    dq.push(make_pair(f->left, p.second + 1));
                }
                if (f->right) {
                    dq.push(make_pair(f->right, p.second + 1));
                }
            }
        }
        int top() {
            if (totNodes > 0) return root->key;
            else return -1;
        }

        void pop() {
            if (totNodes == 0) return;
            totNodes--;
            if (totNodes + 1 == 1) {
                root = NULL;
                return;
            }
            NodePtr p = findParentNode(totNodes + 1);
            int mKey = -1;
            if (p->right) {
                mKey = p->right->key;
                p->right->parent = NULL;
                p->right = NULL;
            } else {
                mKey = p->left->key;
                p->left->parent = NULL;
                p->left = NULL;
            }
            root->key = mKey;
            pushDown(root);
        }

        void pushDown(NodePtr p) {
            int rKey = p->right ? p->right->key: MAX_KEY;
            int lKey = p->left ? p->left->key: MAX_KEY;
            int mKey = min(lKey, rKey);
            if (mKey >= p->key) return;
            if (p->left != NULL && mKey == p->left->key) {
                swap(p->key, p->left->key);
                pushDown(p->left);
            } else if ( p->right != NULL && mKey == p->right->key) {
                swap(p->key, p->right->key);
                pushDown(p->right);
            }
        }

};

Heap heap;
void getInputVector(vector<int> &out) {
    for (int i = 0; i < MAX_SZ; i++) {
        out.push_back(rand() % MAX_KEY);
    }
}

void testHeap() {
    int memSz = heap.totNodes;
    int e[MAX_SZ];
    memset(e, 0, sizeof(int)*memSz);
    for (int i = 0; i < memSz; i++) {
        e[i] = heap.top();
        if (i > 0 && e[i] < e[i-1]) {
            cout << "Shits fucked up \n";
            heap.printLevelOrder();
        }
        heap.pop();
    }
}

int main() {
    vector<int> v;
    getInputVector(v);
    for (int i = 0; i < v.size(); i++) {
        heap.insert(v[i]);
    }
    /*
    cout << "Before deleting\n";
    heap.printLevelOrder();
    heap.pop();
    cout << "After deleting\n";
    heap.printLevelOrder();
    */
    testHeap();
    return 0;
}
