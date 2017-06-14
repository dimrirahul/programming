#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

#define FORN(I,N) for (int (I) = 0; (I) < (N); (I)++)
#define ALL(X) (X).begin(), (X).end()

using PI = pair<int, int>;
using VPI = vector<PI>;
using VI = vector<int>;
using MI = map<int, int>;
const int MX_ELEMENTS = ((int)1e5) + 20;

int getResults(const array<int, MX_ELEMENTS>& pArr, int n) {
    set<int> visited;
    stack<int> stk;
    int moves = 0;
    FORN (i, n) {
        if (visited.count(pArr[i]) > 0) continue;
        int numNodes = 0;
        stk.push(pArr[i]);
        while (!stk.empty()) {
            int p = stk.top();
            stk.pop();
            if (visited.count(p)) continue;
            visited.insert(p);
            numNodes++;
            stk.push(pArr[p]);
        }
        moves += (numNodes - 1);
    }
    return moves;
}

int sortAndGetResult(VPI& vpi, bool isDescending=false) {
    array<int, MX_ELEMENTS> pArr;
    auto less = [](PI a, PI b)->bool { return a.first < b.first;};
    auto more = [](PI a, PI b)->bool { return a.first > b.first;};
    auto fn = isDescending ? more : less;
    sort(ALL(vpi), fn);
    FORN (i, vpi.size()) {
        pArr[vpi[i].second] = i;
    }
    return getResults(pArr, vpi.size());
}
int main() {
    int n; cin >> n;
    VPI vpi;
    FORN (i, n) {
        int t; cin >> t;
        vpi.push_back(make_pair(t, i));
    }
    cout << min(sortAndGetResult(vpi), sortAndGetResult(vpi, true)) << "\n";
    return 0;
}
