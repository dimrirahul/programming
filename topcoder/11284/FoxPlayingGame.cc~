
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


const int MAX_SIZE = 101;
const double MAXD = 1e20;
const double MIND = -1e20;
pair<double, double> g_Values[MAX_SIZE][MAX_SIZE];
class FoxPlayingGame
{
    public:
        void printMatrix(int a, int b) {
            int sum = a + b;
            for (int i = 0; i < sum ; i++) {
                for (int j = 0; j < sum; j++) {
                     cout << "[" << g_Values[i][j].first << ","  << g_Values[i][j].second << "] ";
                }
                cout << "\n";
            }
        }

        void setBaseConditions(int a, int b, double ca, double cb)  {
            for (int i = 0; i < MAX_SIZE; i++) {
                for (int j = 0; j < MAX_SIZE; j++) {
                    g_Values[i][j] = make_pair(MAXD, MIND);
                }
            }
            for ( int i = 0; i <= max(a, b); i++) {
                if (i <= a) {
                    g_Values[i][0] = make_pair(min(MAXD, i * ca), max(MIND, i * ca));
                }
                if (i <= b) {
                    g_Values[0][i] = make_pair(min((double)0, MAXD), max(MIND, (double)0));
                }
            }
        }

        double returnRightAnswer(int a, int b) {
            pair <double, double> tmp = g_Values[a][b];
            return max(tmp.first, tmp.second);
        }

        double theMax(int nA, int nB, int paramA, int paramB)
        {
            double ca, cb;
            ca = (double) paramA / 1000;
            cb = (double) paramB / 1000;
            setBaseConditions(nA, nB, ca, cb);
            for ( int i = 1; i < nA + nB; i++) {
                for (int j = 1; j < nA + nB; j++) {
                    double a, b, c, d;
                    a = g_Values[i][j-1].first * cb;
                    b = g_Values[i][j-1].second * cb;
                    c = g_Values[i-1][j].first + ca;
                    d = g_Values[i-1][j].second + ca;
                    double maxOfFour = max(a, max(b, max(c, d)));
                    double minOfFour = min(a, min(b, min(c, d)));
                    g_Values[i][j] = make_pair(maxOfFour, minOfFour); 
                }
            }
            //printMatrix(nA, nB);
            return returnRightAnswer(nA, nB);
        }
};

