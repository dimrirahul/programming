
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

typedef pair< int, int > PI;
typedef int UI;
/*
const int MAX_INT = 1 << 30;
const int HALF_MAX_INT = 1 << 16;
*/
const int MAX_INT = 1 << 30;
const int HALF_MAX_INT = 1 << 17;

class CollectingPostmarks
{
    public:
        vector<PI> s1, s2;
        /*
           void initArr() {
           REP(i, HALF_MAX_INT) {
           s1[i] = s2[i] = MAX_INT;
           }
           }
           */
        bool isBitSet(UI counter, int bit) {
            return (counter & (1 << bit)) > 0;
        }


        void populateValueArray(vector < PI > & s, vector<int>&v1 , vector<int>&c1) {
            int maxRange = 1 << v1.size() ;

            REP(i, maxRange) {
                int cost = 0;
                int value = 0;
                REP(j, v1.size()) {
                    if (isBitSet(i, j)) {
                        cost += c1[j];
                        value += v1[j];
                    }
                }
                s.push_back(make_pair(value, cost));
            }
            sort(ALL(s));
        }

        void printStuff(vector<PI>& s) {
            REP(i, s.size()) {
                printf("Value = %d, cost =%d\n", s[i].first, s[i].second);
            }
        }

        int amountOfMoney(vector <int> costs, vector <int> have, vector <int> values, int K)
        {
            //  initArr();
            /*
            if (costs.size() % 2 != 0) {
                costs.push_back(0);
                values.push_back(0);
            }
            */
            vector<int> v1, c1, v2, c2;
            REP(i, costs.size()) {
                if (i < costs.size()/2) {
                    v1.push_back(values[i]);
                    c1.push_back(costs[i]);
                } else {
                    v2.push_back(values[i]);
                    c2.push_back(costs[i]);
                }
            }

            populateValueArray(s1, v1, c1);
            populateValueArray(s2, v2, c2);
            /*

               cout << "First Array ====\n";
               printStuff(s1);
               cout << "Second array ====\n";
               printStuff(s2);

            */
            int res = MAX_INT;
            int minCost = MAX_INT;
            int j = s2.size() - 1;
            for (int i = 0; i < s1.size(); i++) {
                for (; j >=0 ; j--) {
                    if ( s1[i].first + s2[j].first >= K ) {
                        minCost = min(s2[j].second, minCost);
                    } else {
                        break;
                    }
                }
                res = min(res, s1[i].second + minCost);
            }


            int haveSum = 0;
            REP(i, have.size()) {
                haveSum += costs[have[i]];
            }

            if (res == MAX_INT) return -1;
            if (res - haveSum > 0) return (res - haveSum);
            return 0;

        }
};

