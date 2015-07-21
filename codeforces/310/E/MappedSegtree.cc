#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstdio>

using namespace std;
using PI = pair<int, int>;
using VI = vector<int>;
using VPI = vector<PI>;

struct Node {
    PI range;
    int left, right;
    VPI storedIntervals;
    Node(PI _range, int parent): range(_range) { 
        left = parent << 1;
        right = (parent << 1) +1;
    }
    void printNode() {
        printf("[%d, %d]\n {", range.first, range.second);
        for (auto& i: storedIntervals) {
            printf("[%d, %d]", i.first, i.second);
        }
        printf("}\n");
    }
};

struct Segtree {
    PI range;
    int root;
    unordered_map<int, Node> nodeById;

    Segtree(PI _range): range(_range), root(1) {};

    bool isLeafNode(PI p) { return (p.second - p.first) == 1;}

    bool isRangeContainedByInterval(PI interval, PI range) {
        return interval.first <= range.first && interval.second >= range.second;
    }

    int addInterval(PI interval, PI range, int curr) {
        auto nodeByIdIter = nodeById.find(curr);
        if (nodeByIdIter == nodeById.end()) { 
            nodeByIdIter = nodeById.emplace(curr, Node(range, curr)).first;
        }
        Node& node = nodeByIdIter->second;

        if (isLeafNode(range) || isRangeContainedByInterval(interval, range)) {
            node.storedIntervals.push_back(interval);
            return curr;
        }

        int mid = (range.first + range.second) >> 1;
        if (interval.first < mid) addInterval(interval, make_pair(range.first, mid), node.left);
        if (interval.second > mid) addInterval(interval, make_pair(mid, range.second), node.right);
        return curr;
    }

    void addInterval(PI interval) {
        addInterval(interval, range, root);
    }

    void findOverlappingIntervals(int key, VPI& out, int curr) {
        const bool dbg = true;
        auto nodeByIdIter = nodeById.find(curr);
        if (nodeByIdIter != nodeById.end()) {
            Node& node = nodeByIdIter->second;
            out.insert(end(out), begin(node.storedIntervals), end(node.storedIntervals));
            if (dbg) printf("key = %d, start = %d, end = %d\n", key, node.range.first, node.range.second);
            if ( key < (node.range.first + node.range.second) / 2) {
                findOverlappingIntervals(key, out, node.left);
            } else {
                findOverlappingIntervals(key, out, node.right);
            }
        } else {
            if (dbg) printf("Unable to find curr = %d\n", curr);
        }
    }

    void findOverlappingIntervals(int key, VPI& out) {
        findOverlappingIntervals(key, out, root);
    }

    void printMap() {
        for (auto& i: nodeById) {
            cout << "Key = " << i.first ;
            i.second.printNode();
        }
    }

    void printTree(int curr) {
        auto nodeByIdIter = nodeById.find(curr);
        if (nodeByIdIter != nodeById.end()) {
            Node& node = nodeByIdIter->second;
            node.printNode();
            printTree(node.left);
            printTree(node.right);
        }
    }
};

Segtree st(make_pair(1, 13));
int main(int argc, char **argv) {
    st.addInterval(make_pair(3, 11));
    st.addInterval(make_pair(4, 10));
    st.printMap();
    st.printTree(st.root);
    VPI out;
    st.findOverlappingIntervals(51, out);
    cout <<"\n";
    for (auto& i: out) {
        printf("[%d, %d] ", i.first, i.second);
    }
    return 0;
}


