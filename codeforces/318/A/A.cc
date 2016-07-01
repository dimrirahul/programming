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


#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

using PI = pair <int, int>;
using VI = vector <int>;
using VS = vector <string>;
using VPI = vector<PI>;

typedef long long LL;
struct A {
    void start() {
        int l, n;
        priority_queue<int> pq;
        cin >> n;
        cin >> l;
        REP(i, n-1) {
            int t;
            cin >> t;
            pq.push(t);
        }

        int res = 0;
        int top = pq.top();
        while (top >= l) {
            res++;
            l++;
            pq.pop();
            top--;
            pq.push(top);
            top = pq.top();
        }
        cout << res << "\n";
    }
};

A t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
