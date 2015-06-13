#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <set>

using namespace std;

const size_t SZ = 10;
const int numQueries = 5;
const int maxV = 4;
using LL = unsigned long long;
const bool dbg = true;
class PartialSumAddQuery {
    public:
        array<LL, SZ> table{};
        vector<int> input;
        void consumeAndSetInput(vector<int> orig) {
            input = move(orig);
        }
        void query(int l, int r, int v) {
            if (dbg) printf("[%d, %d, %d] ", l, r, v);
            table[l] += v;
            table[r] -= v;
        }
        void printResult() {
            LL cumP = 0;
            int idx = 0;
            for (auto &i: input) {
                cumP += table[idx++];
                i += cumP;
                cout << i << ",";
            }
            cout << "\n";
        }
};

vector<int> populateInput() {
    vector<int> res;
    //for (int i = 0; i < SZ; i++) res.insert(end(res), (int)rand());
    for (int i = 0; i < SZ; i++) res.insert(end(res), 0);
    return res;
}

PartialSumAddQuery pcq;
int main(int argc, char **argv) {
    pcq.consumeAndSetInput(populateInput());
    for (int i = 0; i < numQueries; i++) {
        int l = rand() % SZ;
        int r = rand() % SZ;
        int v = rand() % maxV;
        if (l > r) swap(l, r);
        pcq.query(l, r, v);
    }
    pcq.printResult();
    return 0;
}
