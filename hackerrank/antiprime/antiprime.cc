#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
using VI = vector<int>;

const bool dbg = true;
const int MAX_POW = 18;
map<int, int> numByFactorCount;
map<int, int> weededResult;

int intPow(int base, int index) {
    int res = 1;
    for (int i = 0; i < index; i++) {
        res *= base;
    }
    return res;
}

int getVal(VI& primes, VI& mask, int& totFactors) {
    int res = 1;
    totFactors = 1;
    for (size_t i = 0; i < primes.size(); i++) {
        res *= intPow(primes[i], mask[i]);
        if (mask[i] > 0) totFactors *= (mask[i] + 1);
    }
    return res;
}

void insertIntoAp(int totFactors, int currVal) {
    if (numByFactorCount.count(totFactors))
        numByFactorCount.erase(totFactors);

    numByFactorCount.insert(make_pair(totFactors, currVal));
}

void fillAp(VI& primes, VI& mask, int depth) {
    if (depth > 15) return;
    for (size_t i = 1; i < mask.size(); i++) {
        if (mask[i] > mask[i-1]) return;
    }
    int totFactors;
    int currVal = getVal(primes, mask, totFactors);
    auto it = numByFactorCount.find(totFactors);
    if (it == numByFactorCount.end() || it->second > currVal) {
        insertIntoAp(totFactors, currVal);
    }
    for (size_t i = 0; i < mask.size(); i++) {
        VI t = mask;
        t[i]++;
        if (t[i] > MAX_POW) continue;
        fillAp(primes, t, depth + 1);
    }
}

VI weedOut() {
    VI prevIndex;
    VI lastVal;
    VI seqSize;
    size_t pos = 0;
    size_t maxSsIdx = 0;
    for (auto it: numByFactorCount) {
        if (pos == 0) {
            seqSize.push_back(1);
            prevIndex.push_back(-1);
        } else {
            int pos2 = pos - 1;
            while (pos2 >= 0 && lastVal[pos2] > it.second) pos2--;
            prevIndex.push_back(pos2);
            int ss = pos2 >= 0 ? seqSize[pos2] : 0;
            seqSize.push_back(ss + 1);
        }
        if (*(seqSize.rend()) >= seqSize[maxSsIdx]) maxSsIdx = pos + 1;
        lastVal.push_back(it.second);
        pos++;
    }
    VI res;
    while (maxSsIdx != -1) {
        res.push_back(lastVal[maxSsIdx]);
        maxSsIdx = prevIndex[maxSsIdx];
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    VI primes {2, 3, 5, 7, 11, 13};//, 17, 19, 23};
    VI first  {0, 0, 0, 0,  0,  0};//,  0,  0,  0};
    fillAp(primes, first, 0);
    if (dbg) {
        cout << " Before weeding out\n";
        for (auto it : numByFactorCount) {
            cout << it.first << ": " << it.second << "\n";
        }
    }
    VI res =  weedOut();
    int pos = 1;
    if (dbg) {
        for (auto& it: res) {
            cout << pos++ << ":" <<  it << "\n";
        }
    }
    return 0;
}
