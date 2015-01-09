
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


const int MAX_SIZE = 1000001;
bool g_prime[MAX_SIZE];
class DivideAndShift
{
public:

    void populatePrimes(int n) {
        int limit = min(MAX_SIZE, n);
        for (int i = 0; i < limit; i++) {
            g_prime[i] = true;
        }

        int lower = sqrt(limit);
        for (int i = 2; i < lower; i++) {
            if (!g_prime[i]) continue;
            for (int j = i * 2; j <= limit; j+= i) {
                g_prime[j] = false;
            }
        }

    }

    int findSmallestPrime(int n) {
        int result = 1;
        for (int i = 2; i <= n; i++) {
            if (g_prime[i] && n % i == 0) {
                result = i;
                break;
            }
        }
        cout << "Largest prime = " << result << "\n";
        return result;
    }


    int findDistance(int index, int chunkSize) {
        return (min (index, chunkSize - index));
    }

    int findSplitDistance(int pos, int chunkSize) {
        int d;
        int moves = 0;
        int lp = findSmallestPrime(chunkSize); 
        while (chunkSize != 2 && chunkSize != 1) {
            moves++;
            chunkSize = chunkSize / lp;
            pos = pos % chunkSize;
            d = findDistance(pos, chunkSize);
            if (d == 0) {
                break;
            } else if (d == 1) {
                moves++;
                break;
            }
            lp = findSmallestPrime(chunkSize); 
        }
        return moves;
    }


    int getMinDistance(int pos, int chunkSize) {
        return min (findSplitDistance(pos, chunkSize), findDistance(pos, chunkSize));
    }


	int getLeast(int N, int M)
	{
        int moves = 0;
        int chunkSize = N;
        int pos = M -1;

        int d = findDistance(pos, chunkSize);
        if (d == 0) {
            return 0;
        } else if ( d == 1) {
            return 1;
        }

        populatePrimes(N);

        return   getMinDistance(pos, chunkSize); 
	}
};

