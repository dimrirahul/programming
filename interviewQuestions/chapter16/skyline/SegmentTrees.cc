#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdio>

using namespace std;

class Segment {
    public:
        int l, r;
        Segment(int _l, int _r) {
            l = _l;
            r = _r;
        }
        bool operator<(Segment o) const {
            if (l != o.l ) return l < o.l;
            return r < o.l;
        }
        void print() {
            printf("[l=%d, r=%d] ", l, r);
        }
};

class Node;
typedef Node* NodePtr;
class Node {
    public:
        NodePtr l, r, p;
        int lv, rv;
        vector<Segment> intervals;
        Node() {
            l = r = p = NULL;
        }
        void print() {
            if (intervals.size() == 0) return;
            printf("Left=%d, Right=%d\n", lv, rv);
            for (int i = 0; i < intervals.size(); i++) {
                intervals[i].print();
            }
            cout << "\n==============\n";
        }
};

const int LEFT_INTERVAL = 0;
const int RIGHT_INTERVAL = 1000;
const int MAX_NODES = 5000;
const bool dbg = true;
class SegmentTree {
    public:
        Node nodeStore[MAX_NODES];
        int nextNodePos;
        NodePtr root;

        int li, ri;

        NodePtr getNode() {
            if (nextNodePos >= MAX_NODES) return NULL;
            NodePtr p = nodeStore + nextNodePos;
            nextNodePos++;
            return p; 
        }

        SegmentTree(int leftInteval=LEFT_INTERVAL, int rightInterval=RIGHT_INTERVAL) {
            nextNodePos = 0;
            root = NULL;
            li = leftInteval;
            ri = rightInterval;
        }

        void addSegment(Segment s) {
            root = addSegment(s, root, li, ri);
        }

        NodePtr addSegment(Segment s, NodePtr currNode, int sv, int ev) {
            if (dbg) {
                cout << "Adding segment with SV=" << sv << " ending with EV=" << ev;
                s.print();
                cout << "\n";

            }
            if (s.l >= ev || s.r <= sv) return currNode;
            if (!currNode) {
                currNode = getNode();
                currNode->lv = sv;
                currNode->rv = ev;
            }
            int mid = (sv + ev) / 2;
            if (ev - sv == 1) {
                currNode->intervals.push_back(s);
            } else {
                if (s.l <= sv && s.r >= ev) {
                    currNode->intervals.push_back(s);
                } else {
                    currNode->l = addSegment(s, currNode->l, sv, mid);
                    currNode->r = addSegment(s, currNode->r, mid, ev);
                }
            }
            return currNode;
        }

        void printTree(NodePtr node) {
            if (node) {
                node->print();
                printTree(node->l);
                printTree(node->r);
            }    
        }

        void printTree() {
            printTree(root);
            if (dbg) {
                cout << "Total number of nodes created = " << nextNodePos << "\n";
            }
        }

        vector<Segment> query(int num) {
            vector <Segment> res;
            NodePtr curr = root;
            while (curr != NULL) {
                curr->print();
                res.insert(res.end(), curr->intervals.begin(), curr->intervals.end());
                if (num > (curr->lv + curr->rv) /2) curr = curr->r;
                else curr = curr->l;
            }
            return res;
        }

        void printOverlappingIntervals(int num) {
            vector<Segment> res = query(num);
            for (int i = 0; i < res.size(); i++) {
                res[i].print();
            }
            cout << "\n";
        }
};


SegmentTree st(1, 13);
void test() {
    for (int i = 0; i < 20; i++) {
        int v1 = rand();
        v1 %= 100;
        int v2 = rand();
        v2 %= 100;
        Segment s(min(v1, v2), max(v1, v2));
        s.print();
        st.addSegment(s);
    }
    st.printTree();
}

void test1() {
    Segment s(3, 11);
    st.addSegment(s);
    //st.printTree();
    st.printOverlappingIntervals(5);
}
int main(int argc, char **argv) {
    test1();
    return 0;
}
            if (intervals.size() == 0) return;
