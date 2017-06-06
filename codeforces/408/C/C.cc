#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <array>

using namespace std;
const int MX_SZ = ((int)3e5) + 10;
const int MIN_VAL = ((int)1e9 + 20) * -1;
const bool dbg = true;

using VI = vector<int>;
#define FORN(I, N) for (int (I) = 0; (I) < (N); (I)++)
struct A {
    array<VI, MX_SZ> adjList;
    array<int, MX_SZ> strength;

    void start() {
        int n;
        cin >> n;
        int maxStrength = MIN_VAL;
        strength[0] = MIN_VAL;
        FORN (i, n) {
            cin >> strength[i+1];
            maxStrength = max(maxStrength, strength[i+1]);
        }

        FORN (i, n-1) {
            int t1, t2;
            cin >> t1 >> t2;
            adjList[t1].push_back(t2);
            adjList[t2].push_back(t1);
        }

        VI maxValueNodes;

        for (int i = 1; i < strength.size(); i++) {
            if (strength[i] == maxStrength) maxValueNodes.push_back(i);
        }

        int res = maxStrength;
        for (auto it : maxValueNodes) {
            set<int> d1, d2;
            getDistances(it, d1, d2);

            if (d1.find(maxStrength) != d1.end()) {
                res = maxStrength + 1;
            }

            if (d2.find(maxStrength) != d2.end()) {
                res = maxStrength + 2;
            } else if (d2.find(maxStrength -1) != d2.end()) {
                res = maxStrength + 1;
            }

            if (res == maxStrength + 2) break;
        }


    }

    void getDistances(int node, set<int>& d1, set<int>& d2) {
        for (auto it : adjList[node]) {
            d1.insert(strength[it]);

            for (auto it1 : adjList[it]) {
                if (it1 == node) continue;
                d2.insert(strength[it2]);
            }
        }
    }

};

A a;
int main() {
    ios::sync_with_stdio(false);
    a.start();
    return 0;
}
