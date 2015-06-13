#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;
const int SZ = ((int) 2e5 ) + 5;
const int WIDTH = 20;
using VI = vector<int>;
struct RMQ {
    int numElements;
    int table[SZ][WIDTH];

    RMQ() {
        numElements = 0;
        memset(table, 0, sizeof(int) * SZ * WIDTH);
    }

    void createTable(const VI& inp) {
        numElements = inp.size();

        for( int i = 0; i < inp.size(); i++) table[i][0] = inp[i];

        for (int i = 1; (1 << i) < inp.size(); i++) {
            int lHalf = 1 << (i-1);
            for (int j = 0; j < inp.size(); j++) {
                int oIdx = min( j + lHalf, (int) inp.size() -1);
                table[j][i] = min(table[j][i-1], table[oIdx][i-1]);
            }
        }
    }

    int query(int pos, int len) {
        int ll = log2(len);
        if (exp2(ll) == (double) len) return table[pos][ll];
        int oIdx = min(pos + len - (int)exp2(ll), numElements -1);
        return min(table[pos][ll], table[oIdx][ll]);
    }

};

RMQ rmq;

int queryBruteForce(VI& inp, int pos, int len) {
    int minV = INT_MAX;
    for (int i = 0; i < len; i++) minV = min(inp[pos + i], minV);
    return minV;
}

void testRmq() {
    const int numElements = 20000;
    const int p = (int) 3e5;
    set<int> si;
    while ( si.size() < numElements) si.insert(rand() % p);
    VI inp;
    inp.insert(end(inp), begin(si), end(si));
    random_shuffle(begin(inp), end(inp));
    //for (auto& i: inp) cout << i << " ";
    cout << "\n";
    rmq.createTable(inp);
    int x, y;
    for (int i = 0; i < numElements; i++) {
        for (int j = 1; i + j <= numElements; j++) {
            x = rmq.query(i, j);
                /*
            if ((x = rmq.query(i, j)) != (y = queryBruteForce(inp, i, j))) {
                cout << "RMQ = " << x << " BF = " << y << " i, j =" << i << " " << j << "\n";
            }
            */
        }
    }
}

int main(int argc, char **argv) {
    testRmq();
    return 0;
}




