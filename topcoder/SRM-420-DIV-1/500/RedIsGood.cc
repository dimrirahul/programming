
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
typedef pair<int, int> PI;
const int SIZE = 5002;
class RedIsGood
{
public:
    double tableArray[2][SIZE];

    void insertIntoArray(int r, int b, double value) {
        tableArray[(r) %2][b] = value;
    }

    double getFromArray(int r, int b) {
        return tableArray[(r) %2][b];
    }

    void getResult(int r, int b) {
        double res = 0;
        if (r <= 0) {
            res = 0;
        } else if (b <= 0) {
            res = r;
        } else {
            double resLeft =  (1 + getFromArray(r-1, b)) * r/ (r+b);
            double resRight = (getFromArray(r, b-1) -1) * b / (r+b);
            res = max((double)0, resLeft + resRight);
        }
        insertIntoArray(r, b, res);
    }

	double getProfit(int R, int B)
	{
        int r = R, b = B;
        for(int i = 0; i <= r; i++) {
           for(int j = 0; j <= b; j++){
                getResult(i, j);
            }
        }
        return getFromArray(r, b);
	}
};

