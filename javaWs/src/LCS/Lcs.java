package LCS;

/**
 *
 * @author rdimri.
 */
public class Lcs {
    public final int SZ = 100;
    public final int dp[][] = new int[SZ][SZ];

    public String s1;
    public String s2;

    void initDp() {
        for (int i = 0; i < SZ; i++) {
            for (int j = 0; j < SZ; j++) {
                dp[i][j] = -1;
            }
        }
    }
    int backwardDp(int i, int j) {
        if ( i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1.charAt(i) == s2.charAt(j)) {
            dp[i][j] = backwardDp(i - 1, j - 1) + 1;
        } else {
            dp[i][j] = Math.max(Math.max(backwardDp(i - 1, j) , backwardDp(i, j - 1)), backwardDp(i - 1, j - 1));
        }
        return dp[i][j];
    }

    public static void main(String args[]) {
        Lcs lcs = new Lcs();
        lcs.s1 ="XMJYAUZ";
        lcs.s2 = "MZJAWXU";
        lcs.initDp();
        System.out.println("length=" + lcs.backwardDp(lcs.s1.length() - 1, lcs.s2.length() - 1));
    }
}
