#include <iostream>
#include <vector>
#include <set>
#include <array>


using namespace std;
//using LL = unsigned long long;
using LL = unsigned long long;
const size_t MAX_SZ = 10000;

class PartialSumCalculator {
    public:
        array<LL, MAX_SZ> table{};
        void createTable(const vector<int>& inp) {
            table.fill(0);
            LL sum = 0;
            int idx = 0;
            for (auto& i: inp) {
                sum += i;
                table[idx++] = sum;
            }
        }
        LL query(int left, int right) {
            if (left == 0) return table[right];
            return table[right] - table[left-1];
        }
};

PartialSumCalculator psc;
int main(int argc, char **argv) {
    set<int> s;
    while(s.size() < MAX_SZ) s.insert((int)rand());
    vector<int> v;
    v.insert(end(v), begin(s), end(s));
    psc.createTable(v);
    const int numQueries = 1000; 
    for (int i = 0; i < numQueries; i++) {
        auto left = rand() % MAX_SZ;
        auto right = rand() % MAX_SZ;
        if (left > right) swap(left, right);
        cout << psc.query(left, right);
    }
    return 0;
}

