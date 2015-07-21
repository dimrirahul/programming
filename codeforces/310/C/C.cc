#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <stdio.h>
#include <unordered_map>


#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

using PI = pair <int, int>;
using VI = vector <int>;
using VS = vector <string>;

typedef long long LL;
struct C {

    unordered_map<int, VI> vById;
    int findNext(int nf, int &t) {
        VI v = vById[nf];
        if (v.size() == 1) {
            vById.erase(nf);
        } else {
            for (int i = 1; i < v.size(); i++) {
                insertIntoMap(v[i], t);
            }
        }
        t++;
        nf++;
        return nf;
    }

    void insertIntoMap(int val, int &t) {
        vById.emplace(val, VI({val}));
        t++;
    }
    int process() {
        int n, k; cin >> n >> k;
        VI first;
        int t = 0;
        REP(i, k) {
            int _t; cin >> _t;
            VI v;
            REP(j, _t) {
                int _t1; cin >> _t1;
                v.insert(end(v), _t1);
            }
            if (v[0] == 1) { first = move(v); }
            else {
                vById[v[0]] = v;
            }
        }
        int _i = 0;
        while (_i < (first.size() - 1) && (first[_i + 1] - first[_i] == 1)) {
            _i++;
        }
        int nf = first[_i] + 1;
        if (nf > n) return t+1;
        for (_i++; _i < first.size(); _i++) {
            insertIntoMap(first[_i], t);
        }
        do {
            nf = findNext(nf, t);
        } while (nf <= n+1);
        return t;
    }    

    void start() {
        cout << process() -1 << "\n";
    }
};

C t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
