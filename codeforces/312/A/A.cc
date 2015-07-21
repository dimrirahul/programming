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

const bool dbg = false;
typedef long long LL;
struct A {

    void start() {
        int n; cin >> n;
        VPI inp;
        PI start = {0, 0};
        inp.push_back(start);
        REP (i, n) {
            int t1, t2;
            cin >> t1 >> t2;
            inp.push_back({t1, t2});
        }
        sort(ALL(inp));
        auto it = lower_bound(ALL(inp), start);
        int pos = it - inp.begin();
        size_t numElementsRight = inp.size() - pos;
        size_t numElementsLeft = pos;
        if (dbg) {
            cout << it->first << " " << it->second << "\n";
            REP (i, inp.size()) {
                printf("[%d, %d] ", inp[i].first, inp[i].second);
                cout << "\n";
            }
        }
        if (dbg) printf("numLeft = %d, numRight = %d\n", numElementsLeft, numElementsRight);
        LL sum = 0;
        if (numElementsLeft > numElementsRight) {
            auto leftStart = pos - numElementsRight;
            if (leftStart > 0) leftStart--;
            auto rightEnd = inp.size() -1;
            if (dbg) printf("Left > right\n");
            if (dbg) printf("LeftStart = %d, RightEnd = %d\n", leftStart, rightEnd);
            for (int i = leftStart; i <= rightEnd; i++) sum += inp[i].second;
        } else if (numElementsRight > numElementsLeft) {
            auto leftStart = 0;
            auto rightEnd = pos + numElementsLeft;
            if (rightEnd < inp.size()) rightEnd++;
            if (dbg) printf("Right > Left\n");
            if (dbg) printf("LeftStart = %d, RightEnd = %d\n", leftStart, rightEnd);
            for (int i = leftStart; i <= rightEnd; i++) sum += inp[i].second;
        } else {
            auto leftStart = pos - numElementsRight;
            auto rightEnd = pos + numElementsRight;
            if (dbg) printf("Right == Left\n");
            if (dbg) printf("LeftStart = %d, RightEnd = %d\n", leftStart, rightEnd);
            for (int i = leftStart; i <= rightEnd; i++) sum += inp[i].second;
        }
        cout << sum << "\n";
    }    
};

A t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
