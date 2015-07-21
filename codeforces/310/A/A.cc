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

const bool dbg = !true;
typedef long long LL;
struct A {

    int pp(VI &inp) {
        stack<int> stk;
        REP(i, inp.size()) {
            if (!stk.empty()) {
                int t = stk.top();
                if (t != inp[i]) {
                    stk.pop();
                } else {
                    stk.push(inp[i]);
                }
            } else {
                stk.push(inp[i]);
            }
        }
        return stk.size();
    }

    void start() {
        int t; cin >> t;
        string s1;
        cin >> s1;
        VI vi;
        REP(i, s1.size()) {
            if (s1[i] == '0') vi.push_back(0);
            else vi.push_back(1);
        }
        cout << pp(vi) << "\n";
    }    
};

A t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
