#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdio.h>


using namespace std;
using PI = pair<int, int>;
using VPI = vector<PI>;
using VI = vector<int>;
using SI = unordered_set<int>;

const int MX_SZ = (((int)(1e6)) * 2) + 10;

struct A {
    int n;
    int m;
    int k;
    bool isHole[MX_SZ];

    void start() {
        ios::sync_with_stdio(false);
        cin >> n >> m >> k;
        for (int i = 0; i < MX_SZ; i++) isHole[i] = false;

        for (int i = 0; i < m; i++) {
            int t; cin >> t;
            isHole[t] = true;
        }

        int bPos = 1;
        for (int i = 0; i < k; i++) {
            if (isHole[bPos])break;
            int t1, t2;
            //scanf("%d %d\n", &t1, &t2);
            cin >> t1 >> t2;

            if (bPos == t1) {
                bPos = t2;
            } else if (bPos == t2) {
                bPos = t1;
            }

        }

        cout << bPos << "\n";

    }


};


A a;
int main() {
    a.start();
    return 0;
}
