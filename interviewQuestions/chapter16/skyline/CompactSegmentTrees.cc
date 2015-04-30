#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PI;
class Node {
    public:
        int lc, rc, p;
        PI range;
        vector<PI> intervals;
        Node(PI _range) {
            range = _range;
            lc = rc = p = -1;
        }
        Node() {
            range.first = range.second = -1;
            lc = rc = p = -1;
        }
        void printNode() {
            if (intervals.size() == 0) return;
            printf("[lc=%d, rc=%d, range.l=%d, range.r=%d]\n", lc, rc, range.first, range.second);
            for (int i = 0; i < intervals.size(); i++) {
                printf("(%d, %d) ", intervals[i].first, intervals[i].second);
            }
            cout << "\n";
        }
};
typedef unordered_map<int, Node> Store;
class SegmentTree {
    public:
        PI range;
        SegmentTree(PI _range) {
            range = _range;
        }
        Store store;
        int addSegment(PI interval, PI range, int nodeId) {
            if (interval.second <= range.first || interval.first >= range.second) return nodeId;
            if (store.count(nodeId) == 0) {
                store[nodeId] = Node(range);
            }
            Store::iterator it = store.find(nodeId);
            if ((interval.first < range.first && interval.second >= range.second ) || 
                   (range.second - range.first == 1)) {
                (it->second).intervals.push_back(interval);
            } else {
                int mid = (range.first + range.second) / 2;
                it->second.lc = addSegment(interval, make_pair(range.first, mid), 2 * nodeId + 1);
                it->second.rc = addSegment(interval, make_pair(mid, range.second), 2 * nodeId + 2);
            }
            return nodeId;
        }

        void printTree(int nodeId = 0) {
            if (store.count(nodeId) == 0) return;
            store[nodeId].printNode();
            printTree(2 * nodeId + 1);
            printTree(2 * nodeId + 2);
        }

        void addSegment(PI interval) {
            addSegment(interval, range, 0);
        }
};

SegmentTree st(make_pair(1, 13));
int main(int argc, char **argv) {
    st.addSegment(make_pair(3, 11));
    st.printTree();
    return 0;
}
