
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


const int RANGE = 6 * 1000000 + 25;
const int MOD =  1000000007;
int dp[2][RANGE];
class CustomDice
{
public:
    int maxRange;
    void printElements(int index) {
        for (int i = 0 ; i <= maxRange; i++) {
            cout << dp[index][i] << "  ";
        } 
        cout << "\n";
    }
	int countDice(int M)
	{

        maxRange = 6*M - 21;
        if (maxRange < 0) {
            return 0;
        }
        for (int i = 0; i <= maxRange; i++) dp[0][i] =1;
        printElements(0);
        for (int j = 1; j <= 6; j++) {
            for (int i = 0; i<= maxRange; i++) {
                dp[j%2][i] = dp[(j-1)%2][i];
                if (i >= j) {
                    dp[j%2][i] += dp[j%2][i - j];
                    dp[j%2][i] %= MOD;
                }
            }
            printElements(j%2);
        }
        return (int) (((long long )30 * dp[0][maxRange]) % MOD);
    }
};

CustomDice cd;
int main(int argc, char **Argv) {
    int ans = cd.countDice(atoi(Argv[1]));
    cout << "\n Answer = " << ans << "\n";
    return 0;
}
