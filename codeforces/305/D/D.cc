#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <array>
#include <cstring>

using namespace std;

using SI = set<int>;
using VI = vector<int>;

#define REP(I, N) for(int (I) = 0; (I) < (N); (I)++) 
const int SZ = (int) 2e5 + 10;
const int WIDTH = 20;
struct RMQ {
    int table[SZ][WIDTH];
    //array< array<int, ((int) log2(SZ) + 3)>, SZ> table;
    array<int, 31> powers;
    int tableSz;

    void populatePowers() {
        REP(i, 30) powers[i] = 1 << i;
    }

    int findLog(int val) {
        int res = 0;
        while (val > 1) {
            val = val >> 1;
            res++;
        }
        return res;
    }

    void resetTable() {
        memset(table, 0, sizeof(int) * SZ * WIDTH);
    }

    RMQ() {
        populatePowers();
        resetTable();
    }

    void populateTable(VI& inp) {
        tableSz = inp.size();
        REP(i, inp.size()) table[i][0] = inp[i];

        for (int i = 1; (1 << i) < inp.size(); i++) {
            int len = 1 << (i-1);
            int logLen = i - 1;
            REP(j, inp.size()) {
                int oIdx = min(j + len, tableSz);
                table[j][i] = min(table[j][logLen] , table[oIdx][logLen]);
            }
        }
    }

    int query(int startIdx, int len) {
        int log = findLog(len);
        return min(table[startIdx][log], table[startIdx + len - (1 << log)][log]);
    }

    void printTable() {
        for (int i = 0; i < tableSz; i++) {
            for (int j = 0; (1 << j) < tableSz; j++) { 
                cout << table[i][j] << " ";
            }
            cout << "\n";
        }
    }

};

RMQ rmq;

int getMinInRange(int start, int len, VI& inp) {
    int minV = SZ;
    for (int i = 0; i <= len; i++) minV = min(minV, inp[start + i]);
    return minV;
}
void testRMQ() {
    SI si;
    while (si.size() < 1000) {
        si.insert(rand() % SZ);
    }
    VI inp;
    inp.insert(end(inp), begin(si), end(si));
    random_shuffle(begin(inp), end(inp));
    rmq.populateTable(inp);
    /*
    cout << " Entries " << "\n";
    for (auto &i: inp) cout << i << " ";
    cout << "\n";
    rmq.printTable();
    */
    REP(i, inp.size()) {
        for (int j = 1; i + j <= inp.size(); j++) {
            //cout << "[" << i << " " << j << " = " << rmq.query(i, j) << "\n";
            if (rmq.query(i, j) != getMinInRange(i, j, inp)) {
                cout << "Wrong Ans ";
            }
        }
    }
}

int main(int argc, char **argv) {
    testRMQ();
    return 0;
}
