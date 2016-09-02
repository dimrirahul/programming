#include <math.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
const bool dbg = !true;

bool findSetSizes(int nodes, int cliqueSize, int& sizeOfPartition, int& numberOfPartions) {
    sizeOfPartition = nodes/cliqueSize;
    if (nodes > cliqueSize) sizeOfPartition++;
    if (nodes < cliqueSize) return false;
    numberOfPartions =((cliqueSize * sizeOfPartition) - cliqueSize - nodes) * -1;
    if (dbg) cout << "Inputs are nodes= " << nodes << " cliqueSize= " << cliqueSize << "\n";
    if (dbg) cout << "Function findSetSizes sizeOfPartition= " << sizeOfPartition << " numberOfPartions=" << numberOfPartions << "\n";
    return true;
}

bool hasCliqueForSure(int nodes, int edges, int size) {
    int sz = size - 1;
    int szPart, numPart;
    if (!findSetSizes(nodes, sz, szPart, numPart)) return false;
    int x1, y1, x2, y2;
    x1 = szPart;
    y1 = numPart;
    x2 = x1 -1;
    y2 = max(0, sz - numPart);
    int res = ((x1 * y1) * (x2 * y2 + (y1 - 1) * x1)) + ((x2 * y2) * (x1 * y1 + (y2 -1) * x2));
    res /= 2;
    if (dbg) cout << "x1=" << x1 << " y1=" << y1 << " x2=" << x2 << " y2=" << y2 << " res=" << res << " edges=" << edges << " size=" << size << "\n";
    return edges > res;
}

int main() {
    int t, n, e;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> e;
        if (dbg) cout << "New test case====\n";

        int high = ((n * (n-1))/2) + 10;
        int low = 2;
        int res = low;
        if (dbg) cout << "high=" << high << " low=" << low << "\n";
        while (low < high) {
            int mid = (low + high)/2;
            if (hasCliqueForSure(n, e, mid)) {
                if (dbg) cout << "has clique for nodes=" << n << " edges=" << e << " and clique size=" << mid << "\n";
                res = mid;
                low = mid + 1;
            } else {
                if (dbg) cout << "DOES NOT has clique for nodes=" << n << " edges=" << e << " and clique size=" << mid << "\n";
                high = mid;
            }
        };
        cout << res << "\n";
    }
    return 0;
}
