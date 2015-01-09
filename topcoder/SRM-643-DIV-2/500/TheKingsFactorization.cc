
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
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
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}
const int SZ = 1000000000;
typedef long long LL;
class TheKingsFactorization
{
public:
    bool isPrime[SZ];
    void generatePrimes() {
        REP (i, SZ) {
            if (i %2 == 0 || i %3 == 0 || i % 5 == 0) {
                isPrime[i] = false;
            } else {
                isPrime[i] = true;
            }
        }
        isPrime[2] = true; isPrime[3] = true; isPrime[5] == true;
        for (int i = 6; i <= SZ; i++) {
            if (isPrime[i]) {
                for (int j = 2; j * i <= SZ; j++ ) {
                    isPrime[i * j] = false;
                }
            }
        }
    }

    LL findPrimeFactor(LL n, LL s, LL e) {
        if (s == e) return s;
        for (int i = s +1 ; i < e; i++) {
            if (isPrime[i] && n % i == 0) return i;
        }
        return -1;
    }
    vector<long long> getVector(long long N, vector<long long> primes)
    {
        vector<LL> res;
        vector< pair<LL, LL> > draw;
        REP (i, primes.size()) {
            res.push_back(primes[i]);
            if (i+1 < primes.size()) {
                LL t = findPrimeFactor(N, primes[i], primes[i+1]);
                if ( t == -1 ) {
                    draw.push_back(make_pair(primes[i], primes[i+1]));
                } else {
                    res.push_back(t);
                }
            } else {
                LL t = findPrimeFactor(N, primes[i], N);
                if ( t == -1 ) {
                    draw.push_back(make_pair(primes[i], N));
                } else {
                    res.push_back(t);
                }
            }
        }
        return res;
    }

};

