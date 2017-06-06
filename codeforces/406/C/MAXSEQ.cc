#include <iostream>
#include <vector>
#include <map>

using namespace std;
using VI = vector<int>;
using LL = long long;
using VL = vector<LL>;

#define FORN(I, N) for (int (I) = 0; (I) < (N); (I)++)
void kadane(int idx, const VI& inp, VL& cumSum) {
    if (idx == 0) {
        cumSum[idx] = inp[idx];
        return;
    }
    kadane(idx -1, inp, cumSum);
    cumSum[idx] =  inp[idx] + max((LL)0, cumSum[idx-1]);
}

int main() {
    VI inp;
    VL cumSum;
    int n; cin >> n;

    FORN(i, n) {
        int t; cin >> t;
        inp.push_back(t);
        cumSum.push_back(0);
    }
    kadane(n-1, inp, cumSum);
    LL maxSum = *(max_element(cumSum.begin(), cumSum.end()));
    cout << maxSum << "\n";
    return 0;

}
