#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

#define FORN(I, N) for (int (I) = 0; (I) < (N); (I)++)
#define ALL(X) (X).begin(),(X).end()


using VI = vector<int>;
using PI = pair<int, int>;
using VPI = vector<pair<int, int>>;
using SI = set<int>;

int getMoves(const VI& rankArr) {
    int res = 0;
    SI visited;
    for (auto it : rankArr) {
        if (visited.count(it)) continue;
        int links = 0;
        int curr = it;
        visited.insert(curr);
        int next = rankArr[it];
        while (next != it) {
            links++
        }
    }

}
int main() {
    VI inp;
    VPI vpi;
    int n;
    cin >> n;
    FORN (i, n) {
        int t; cin >> t;
        inp.push_back(t);
        vpi.push_back(make_pair(t, i));
    }
    sort(ALL(vpi));
    VI rankArr;
    for (auto &it : vpi) rankArr.push_back(it.second);
    cout << getMoves(rankArr) << "\n";
    return 0;
}
