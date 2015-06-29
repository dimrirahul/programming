#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define REP(I, N) for (int (I) = 0; (I) < (N); (I)++)
const int SZ = (int)2e5 + 10; 
const int WIDTH = 20;
struct RMQ {
    int table[SZ][WIDTH];
    int numElements;

    RMQ() {
        memset(table, 0, sizeof(int) * SZ * WIDTH);
        numElements = 0;
    }

    void createTable(const vector<int>& inp) {
        numElements = inp.size();
        REP(i, inp.size()) table[i][0] = inp[i];

        for (int i = 1; )
    }

}
