#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long int LL;
class Node;
typedef Node* NodePtr;
class Node {
    public:
        int value;
        NodePtr l, r, p;
        int rank;
        Node() {
            reset();
        }
        void reset() {
            l = r = p = NULL;
            rank = 1;
        }
        void print() {
            cout << "Value = " << value << " Rank = " << rank << "\n";  
        } 
};
const int SZ = 2e5 + 10;
class RankedTree {
    public:
        Node store[SZ];
        size_t storePos;
        NodePtr root;
        
        RankedTree() {
            reset();
        }

        void reset() {
            storePos = 0;
            root = NULL;
            for (int i = 0; i < SZ; i++) store[i].reset();
        }
        
        NodePtr getNode(int v) {
            store[storePos].value = v;
            NodePtr ret = store + storePos;
            storePos++;
            return ret;
        }

        void addNode(int v) {
            NodePtr node = getNode(v);
            if (!root) {
                root = node;
            } else {
                NodePtr curr = root, prev = NULL;
                while (curr) {
                    curr->rank++;
                    prev = curr;
                    if (v >= curr->value) {
                        curr = curr->r;
                    } else {
                        curr = curr->l;
                    }
                }
                if (v >= prev->value) {
                    prev->r = node;
                } else {
                    prev->l = node;
                }
                node->p = prev;
            }
        }
        int getRank(int v) {
            int res = 0;
            NodePtr curr = root;
            while (curr && curr->value != v) {
                if (curr->value < v) {
                    if (curr->l) {res += curr->l->rank;}
                    res++;
                    curr = curr->r;
                } else {
                    curr = curr->l;
                }
            } 
            if (curr) {
                if (curr->l) res += curr->l->rank;
            }
            return res;
        }

        void printTree(NodePtr curr) {
            if (curr) {
                curr->print();
                printTree(curr->l);
                printTree(curr->r);
            }
        } 

        void start() {
            int numTests, countInput, input;
            cin >> numTests;
            for (int i = 0; i < numTests; i++) {
                reset();
                vector<int> vi;
                cin >> countInput;
                for (int j = 0; j < countInput; j++) {
                    cin >> input;
                    vi.push_back(input);
                }
                solve(vi);
                //printTree(root);
            }
        }

        void solve(vector<int> vi) {
            //Add worst case checks.
            LL res = 0; 
            for (int i = vi.size() -1; i >= 0; i--) {
                res += getRank(vi[i]);
                addNode(vi[i]);
            }
            cout <<  res << "\n";
        }
};

RankedTree rt;

int getRank(set <int> si, int key) {
    int res = 0;
    for (set<int>::const_iterator it = si.begin(); it != si.end() && *it != key; it++) res++;
    return res;
}
void test() {
    set <int> si;
    for (int i = 0; i < 100; i++) {
        int num = rand();
        num %= (int)1e7;
        si.insert(num);
    }
    vector <int> vi (si.begin(), si.end());
    random_shuffle(vi.begin(), vi.end());
    for (int i = 0; i < vi.size(); i++) {
        rt.addNode(vi[i]);
    }
    for (int i = 0; i < vi.size(); i++) {
        int currRank;
        if ((currRank = getRank(si, vi[i])) != rt.getRank(vi[i])) {
            cout << "Things fucked up\n";
        } else {
            cout << "Test Succeded for " << vi[i] << "  its rank is " << currRank << "\n";
        }
    }
}
int main(int argc, char **argv) {
    /*
    vector<int> inp;
    inp.push_back(2);
    inp.push_back(3);
    inp.push_back(8);
    inp.push_back(6);
    inp.push_back(1);
    for (int i = 0; i < inp.size(); i++) {
        rt.addNode(inp[i]);
        rt.printTree(rt.root);
        cout << "===========\n";
    }
    for (int i = 0; i < inp.size(); i++) {
        cout << "Rank of " << inp[i] << " = " << rt.getRank(inp[i]) << "\n";
    }
    rt.printTree(rt.root);
    */
    //test();
    rt.start();
    return 0;
}
