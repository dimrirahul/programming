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
#include <climits>


#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

using PI = pair <int, int>;
using VI = vector <int>;
using VS = vector <string>;
using SI = set <int>;
using KEY = pair<int, SI>;

const bool dbg = true;
typedef long long LL;
struct C {
    int m, w;
    VI baseW;

    void convertToBase(int num, int base, VI& out) {
        while (num > 0) {
            int d = num / base;
            int rem =  num - (d * base);
            num = d;
            out.push_back(rem);
        }
        REP(i, 4) out.push_back(0);
        reverse(ALL(out));
    }

    void balanceWeights(VI& input, int base) {
        for (int i = input.size() - 1; i > 0; i--) {
            if (input[i] < 2) continue;
            input[i] -= base;
            input[i-1]++;
        }
    }

    bool limitsMet(VI& input) {
        for(auto& i: input) {
            if (abs(i) > 1) return false;
        }
        return true;
    }

    void printAdjustedWeights(VI& input) {
        for (auto &i: input) cout << i << " ";
        cout << "\n";
    }

    void start() {
        cin >> w >> m;
        convertToBase(m, w, baseW);
        balanceWeights(baseW, w);
        bool res = limitsMet(baseW);
        if (dbg) printAdjustedWeights(baseW); 
        if (res) cout << "YES\n";
        else cout << "NO\n";
    }    
};

C t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
