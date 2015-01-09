
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

class PrimeSoccer
{
    public:

        vector<int> primes;
        vector<long long> fact;
        int numPrimes;
        int totIntervals;

        void init() {
            numPrimes = 7;
            totIntervals = 18;
            primes.push_back(2);
            primes.push_back(3);
            primes.push_back(5);
            primes.push_back(7);
            primes.push_back(11);
            primes.push_back(13);
            primes.push_back(17);

            long long num = 1;
            for (int i = 1; i <= totIntervals; i++) {
                num *= i;
                fact.push_back(num);
            }

        }
        double exceptRGoals(int p, int r, int tot) {
            return 1 - exactlyRGoals(p, r, tot);
        }

        double calcX(int pa) {
            double res = 0;
            for (int i = 0; i < numPrimes; i++) {
                double p1 = exactlyRGoals(pa, primes[i], totIntervals);
                res += (p1);
            }
            return res;
        }

        double calcY(int pa, int pb) {
            double res = 0;
            for (int i = 0; i < numPrimes; i++) {
                double p1 = exactlyRGoals(pa, primes[i], totIntervals);
                double p2 = 0;
                for (int j = 0; j < numPrimes; j++) {
                    p2 += exactlyRGoals(pb, primes[i], totIntervals);
                }
                res += (p1 * p2);
            }
            return res;
        }
        
        long long nCr(int n, int r) {
            long long res = (fact[n-1] / (fact[r-1] * fact [n-r-1]));
            return res;
        }

        double exactlyRGoals(int p, int r, int tot) {
            double res1 =  pow(p, r);
            int t = 100 - p;
            double res2 = pow(t , tot-r);
            double res = res1 *res2 * nCr(tot, r) / pow(100, tot);
            printf("Probablity of exactly %d goals, totGoals = %d with interval probabliety = %d, t=%d, res1=%lf, res2=%lf res = %lf\n", r, tot, p, t, res1, res2, res);
            return res;
        }
        double getProbability(int skillOfTeamA, int skillOfTeamB)
        {
            init();
            //2, 3 , 5, 7, 11, 13, 17
            double res = 0;

            double pa = calcX(skillOfTeamA);
            double pb = calcX(skillOfTeamB);
            res =  pa + pb - (pa *pb);
            return res; 
        }
};

