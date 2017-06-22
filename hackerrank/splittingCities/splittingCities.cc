#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;


const int MX_SIZE = (((int)1e5) * 2) + 20;

struct Node;

struct Node {
    int id;
    bool merged;
    vector<int> neighbors;
    vector<int> mergedNeighbors;
    Node *parentArr;

    void initialize (int inpId, Node* inpParentArr) {
        id = inpId;
        merged = false;
        parentArr = inpParentArr;
    }

    bool isSingle() {
        return !merged && neighbors.size() == 1;
    }

    void addNeighbor(int neighbor) {
        neighbors.push_back(neighbor);
    }

    void mergeWithParent() {
        int parentId = *neighbors.begin();
        Node *parent = parentArr + parentId;
        parent->mergedNeighbors.push_back(id);
        merged = true;
    }

};

Node nodeArr[MX_SIZE];

int doModularExp(int b, int e, int m) {
    int res = 1;
    for (int i = 0; i < e; i++) {
        int t = (res) * (b % m);
        res = t % m;
    }
    return res;
}

int main() {
    for (int i = 0; i < MX_SIZE; i++)
        nodeArr[i].initialize(i, nodeArr);

    int numNodes;
    cin >> numNodes;

    for (int i = 0; i < numNodes-1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--;
        t2--;
        nodeArr[t1].addNeighbor(t2);
        nodeArr[t2].addNeighbor(t1);
    }

    for (int i = 0; i < numNodes; i++) {
        if (nodeArr[i].isSingle())
            nodeArr[i].mergeWithParent();
    }

    int goodNodes = 0;
    for (int i = 0; i < numNodes; i++)
        if (!nodeArr[i].merged)
            goodNodes++;


    cout << doModularExp(2, goodNodes, ((int)1e9) + 7) << "\n";
    return 0;
}

