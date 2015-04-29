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
        set < Segment> intervals;
        Node() {
            l = r = p = NULL;
        }
        void print() {
            printf("Left=%d, Right=%d\n", lv, rv);
            for (int i = 0; i < intervals.size(); i++) {
                intervals[i].print();
            }
            cout << "==============\n";
        }
};

const int LEFT_INTERVAL = 0;
const int RIGHT_INTERVAL = 1000;
const int MAX_NODES = 5000;
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

        SegmentTree() {
            nextNodePos = 0;
            root = NULL;
            li = LEFT_INTERVAL;
            ri = RIGHT_INTERVAL;
        }

        void addSegment(Segment s, int sv, int ev, &NodePtr node) {
            cout << "Adding segment with bounds " << sv << " " << ev << "\n";
            s.print();
            if (!node) {
                node = getNode();
                node->lv = sv;
                node->rv = ev;
            }

            if (s.l >= sv   && s.r <= ev) {
                node->intervals.insert(s);
            } else if (s.r <= sv){
                addSegment(s, sv, ev/2, node->l);
            } else {
                addSegment(s, sv/2, ev, node->r);
            }
        }

        void printTree(NodePtr node) {
            if (node) {
                node->print();
                printTree(node->l);
                printTree(node->r);
            }    
        }
};

SegmentTree st;
void test() {
    for (int i = 0; i < 20; i++) {
        int v1 = rand();
        v1 %= 100;
        int v2 = rand();
        v2 %= 100;
        Segment s(min(v1, v2), max(v1, v2));
        s.print();
        st.addSegment(s, LEFT_INTERVAL, RIGHT_INTERVAL, st.root);
    }
    st.printTree(st.root);
}
int main(int argc, char **argv) {
    test();
    return 0;
}
