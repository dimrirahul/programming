package integerWalk;

/**
 * Created by rdimri on 2/27/15.
 */
public class IntegerWalk {
    long dp[] = new long [101];
    private long f(int x) {

        if (x == 0) return 0;
        if (x == 1) return 1;
        if (dp[x] != 0) return dp[x];
        long res = 0;
        for (int i = 1; i <= x; i++) res += (1 + f(x - i));
        dp[x] = res;
        return res;

    }
    public boolean integerWalk(int a, int b) {
        long fa = f(a);
        long fb = f(b);
        System.out.println("F(a) =" + fa);
        System.out.println("F(b) =" + fb);
        for (int i = 0; i < 101; i++) {
            System.out.println("dp[" + i + "] =" + dp[i]);
        }
        return (f(a) * f(b)) % 2 == 1;

    }

}
