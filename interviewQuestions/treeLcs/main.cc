#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include "BinaryTree.h"

using namespace std;

BinaryTreeBase bt;

void populateTree() {
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; i++) {
        int p;
        scanf("%d ", &p);
        bt.addNode(p);
    }
}

void printRandomNumbers(int count) {
    vector<int> v;
    set<int> s;
    for (int i = 0; i < count * 2; i++) {
        int t = rand() % 500;
        if (s.count(t) > 0) continue;
        s.insert(t);
        v.push_back(t);
    }

    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
}
int main(int argc, char **Argv) {
    //printRandomNumbers(40);
    populateTree();
    //bt.printReverseInorder();
    bt.printLevelOrder();
    bt.printCommonAncestor(190, 335);
    return 0;
}
