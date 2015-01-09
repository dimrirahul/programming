
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

typedef vector<int> VI;
class ProductOfDigits
{
public:
    vector<int> primes;
    int factors[10];
    void initPrimes() {
        primes.push_back(2);
        primes.push_back(3);
        primes.push_back(5);
        primes.push_back(7);
        REP(i, 10) {
            factors[i] = 0;
        }
    }
    bool populateV(int n) {
        REP(i, primes.size()) {
            while (n % primes[i] == 0) {
                factors[primes[i]]++;
                n = n/primes[i];
            }
        }
        return (n == 1);
    }
    
    void flattenFactors() {
        while(factors[2] > 1) {
            if (factors[2] >= 3) {
                factors[8]++;
                factors[2] -= 3;
            } else if(factors[2] >= 2) {
                factors[4]++;
                factors[2] -= 2;
            }
        }
        
        while(factors[3] > 1) {
             if (factors[3] >= 2) {
                factors[9]++;
                factors[3] -= 2;
            }
        }

        while(factors[2] > 0 && factors[3] > 0) {
            factors[2]--;
            factors[3]--;
            factors[6]++;
        }
    }
	int smallestNumber(int N)
	{
        initPrimes();
        if (N==1) return 1;
        bool possible = populateV(N);
        if (!possible) return -1;
        flattenFactors();
        int sum = 0;
        REP(i, 10) {
            sum += factors[i];
        }
		return sum;
	}
};

