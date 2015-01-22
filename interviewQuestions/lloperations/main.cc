#include <iostream>
#include "ll.h"
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
Ll l1, l2;
const int BUF_SIZE = 1000;

vector<int> readIntsOnOneLine() {
    string buff;
    vector<int> res;
    getline(cin, buff);
    stringstream ss(buff);
    int t;
    while (ss >> t) {
        res.push_back(t);
    }
    sort(res.begin(), res.end());
    return res;
}
int main(int argc, char **Argv) {
    vector<int> v1 = readIntsOnOneLine();
    for (int i = 0; i < v1.size(); i++) {
        l1.addNode(v1[i]);
    }
    vector<int> v2 = readIntsOnOneLine();
    for (int i = 0; i < v2.size(); i++) {
        l2.addNode(v2[i]);
    }
    printf("List 1\n");
    l1.printList();
    printf("List 2\n");
    l2.printList();

    l1.mergeList(l2);
    printf("=======Merged list========\n");
    l1.printList();
    printf("======== Iterativeley reversing List=====\n");
    l1.reverseListIteratively();
    l1.makeListCircular(56);
    if (l1.hasLoop()) {
        cout << "l1 has loop" << "\n";
    } else {
        cout << "l1 does NOT have loop \n";
        l1.printList();
    }
    return 0;
}
