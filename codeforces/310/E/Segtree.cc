#include <set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
using PI = pair<int, int>;
using SPI = set<PI>;
using VPI = vector<PI>;
const int MAX_NODES = (int) 1e6;
struct Node;
typedef Node* NodePtr;
void printPI(PI pi) {
    cout << "[" << pi.first << "," << pi.second << "]";
}
struct Node {
    NodePtr left, right;
    PI range;
    SPI intervalSet;
    Node(PI _range): range(_range) {
        left = right = NULL;
    }
    Node() { left = right = NULL;}
    void print() {
        printPI(range);
        cout << "\n{";
        for (auto& i: intervalSet) {
            printPI(i) ;
            cout << ",";
        }
        cout << "}\n";
    }
};

struct Mempool {
    int curr;
    Node pool[MAX_NODES];
    Mempool() {
        curr = 0;
    }
    NodePtr getNode() {
        if (curr < MAX_NODES) return &pool[curr++];
        else {
            cout << "Out of memory\n";
            return NULL;
        }
    }
};

struct SegTree {
    NodePtr root;
    PI range;
    Mempool mempool;

    SegTree(PI _range): range(_range), root(NULL){}

    bool isLastNode(PI pi) {
        return pi.second - pi.first  == 1;
    }

    bool isIntervalLargerThanRange(PI interval, PI range) {
        return (interval.second >= range.second && interval.first <= range.first);
    }
    NodePtr addInterval(PI interval, PI range, NodePtr curr) {
        if (curr == NULL) {
            curr = mempool.getNode();
            curr->range = range;
        }
        if (isLastNode(range) || isIntervalLargerThanRange(interval, range)) {
            curr->intervalSet.insert(interval);
            return curr;
        }
        int mid = (range.first + range.second) / 2;
        if (interval.first < mid) {
            curr->left = addInterval(interval, make_pair(range.first, mid), curr->left);
        }
        if (interval.second > mid) {
            curr->right = addInterval(interval, make_pair(mid, range.second), curr->right);
        }
        return curr;
    }

    void findOverlappingIntervals(int key, VPI& out) {
        NodePtr curr = root;
        do {
            out.insert(out.end(), curr->intervalSet.begin(), curr->intervalSet.end());
            if (key <= (curr->range.first + curr->range.second)/2) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        } while (curr != NULL);
    }
    
   void addInterval(PI interval) {
        root = addInterval(interval, range, root);
    }

   void printTree(NodePtr curr) {
        if (curr) {
            curr->print();
            printTree(curr->left);
            printTree(curr->right);
        }
   }   

   void printTree() {
       printTree(root);
   }
};

SegTree st(make_pair(1, 13));
int main(int argc, char **argv) {
    st.addInterval(make_pair(3, 7));
    /*
    VPI out;
    st.findOverlappingIntervals(5, out);
    cout << "Intervals for 5\n";
    for (auto& i: out) {
        printPI(i);
    }
    cout << "\n";
    */
    st.printTree();
    return 0;
}

    
