
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

const int MAX = 1000002;
class InverseFactoring
{
public:
    /*
    bool isPrime[MAX/2];
    map<int, int> primesMap;
    void generatePrimes() {
        for(int i = 0; i < MAX/2; i++) {
            isPrime[i] = true;
        }
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < MAX/2; i++) {
            if (isPrime[i]) {
                for (int j = 2; i * j < MAX/2; j++) {
                    isPrime[j*i] = false;
                }
            }
        }
    }

    map<int, int> calculateFactor(int value) {
        map<int, int> resMap;
        int origValue = value;
        while (value > 1) {
            for (int i = 2; i <= value; i++) {
                if (isPrime[i] && (value % i == 0)) {
                    map<int, int>::iterator it = resMap.find(i);
                    if (it != resMap.end()) {
                        (it->second)++;
                    }else {
                        resMap[i] = 1;
                    }

                    value = value/i;
                    break;
                }
            }
        }
        
  //      printf("factors of %d\n", origValue);
        for(map<int, int>::const_iterator it = resMap.begin(); it != resMap.end(); it++) {
    //        printf("key =%d value=%d\n", it->first, it->second);
        }
        return resMap;
    }

    int populateFactors(vector<int>& factors) {
        map<int, int> resMap;
        map<int, int> tempMap;
        map<int, int> addMap;
        REP(i, factors.size()) {
            tempMap = calculateFactor(factors[i]);
            for (map<int, int>::iterator it1 = tempMap.begin(); it1!= tempMap.end(); it1++) {
                map<int, int>::iterator it2 = resMap.find(it1->first);
                if (it2 != resMap.end() && it2->second < it1->second) {
                    resMap[it1->first] = it1->second;
                } else if(it2 == resMap.end()){
                    resMap[it1->first] = it1->second;
                }
            }
        }

        int res = 1;
        for (map<int, int>::iterator it = resMap.begin(); it != resMap.end(); it++) {
            res *= (pow(it->first, it->second));
        }

        bool notAFactor = true;
        REP(i, factors.size()) {
            if (factors[i] == res) {
                notAFactor = false;
                break;
            }
        }
        
        if (notAFactor) {
            return res;
        }

        map<int, int>::const_iterator it = resMap.begin();
//        printf("Res=%d was found as a factor multiplying it with=%d\n", res, it->first);
        return res * it->first;
    }
	int getTheNumber(vector <int> factors)
	{
        generatePrimes();
        return populateFactors(factors);
	}
    */
};

