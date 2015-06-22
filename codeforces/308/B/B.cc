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

typedef long long LL;
struct B {
    
    int log(int num) {
        int res = 0;
        while (num > 0) {
            res++;
            num /= 10;
        }
        return res;
    }
    LL pow(int exp) {
        LL res = 1;
        while(exp > 0) {
            res *= 10;
            exp--;
        }
        return res;
    }
    void start() {
        int t; cin >> t;
        int maxP = log(t);
        maxP--;
        LL res = 0;
        for (int i = 1; i <= maxP; i++) {
            res += ( i * (pow(i) - pow(i-1)));
        }
        res += ((maxP + 1) * (t - pow(maxP) + 1));
        cout << res << "\n";
    }    
};

B t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
