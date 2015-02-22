
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=java:foldmethod=marker:foldmarker={{{,}}}



// }}}

import java.util.ArrayList;

public class KSubstring
{
    int N;
    ArrayList <int> seq;
    int dp[][] = new int [SZ][SZ];

    void populateSeq(int _a, int _x, int _y, int _m, int _n) {
        long long temp = _a;
        for (int i = 0; i < _n; i++) {
            seq.push_back((int) temp);
            temp *= _x;
            temp %= _m;
            temp += _y;
            temp %= _m;
        }
    }
    //n^3 solution which should not run.
    //1) Populate DP array i, j where i is the starting position and j is the length of the string.
    //2) Brute force for all strings begining with i and j of lenght k find result and update it.


    vector<int> bruteForce(int _a, int _x, int _y, int _m, int _n) {
        N = _n;
        int n = _n;
        for (int i = 0 ; i < n; i++) {
            for (int j = 1; i + j <= n; j++) {
                if (j == 1) {
                    dp[i][j] = seq[i];
                    continue;
                }
                dp[i][j] = dp[i][j-1] + seq[i+j];
            }
        }

        int mv = 1000000000; int mk = 0;
        for (int k = 1; k < n; k++) {
            for (int i = 0; i + k < n; i++) {
                for (int j = i + 1; j + k < n && i + k <= j; j++) {
                    int v = abs(dp[i][k] - dp[j][k]);
                    if (v < mv) {
                        mv = v;
                        mk = k;
                    } else if (v == mv && mk < k) {
                        mk = k;
                    }
                }
            }
        }
        int res[] = new int[2];
        res[0] = mk;
        res[1] = mv;
        return res;
    }


    public int[] maxSubstring(int A0, int X, int Y, int M, int n)
	{
        populateSeq(A0, X, Y, M, N);
        return bruteForce(A0, X, Y, M, N);

    }

    void
    int main(int argc, String argv[]) {

    }
}

