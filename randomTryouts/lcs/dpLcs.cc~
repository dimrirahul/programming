#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;
const int MAX_SZ = 100;
class OptimizedLcs {
    public:
        char str1[MAX_SZ];
        char str2[MAX_SZ];

        int dp[MAX_SZ][MAX_SZ];

        void getLcs() {
            scanf("%s\n", str1);
            scanf("%s\n", str2);
            int s1Len = strlen(str1);
            int s2Len = strlen(str2);
            for (int i = 0; i <= s1Len; i++) {
                for (int j = 0; j <= s2Len; j++) {
                    if (i == 0 || j == 0)  {
                        dp[i][j] = 0;
                        continue;
                    }
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    if (str1[i-1] == str2[j-1]) {
                        dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                    }
                }
            }

            for (int i = 0; i <= s1Len; i++) {
                for (int j = 0; j <= s2Len; j++) {
                    printf("%d ", dp[i][j]);
                }
                printf("\n");
            }

            printf("Res = %d\n", dp[s1Len][s2Len]);
        }

};

OptimizedLcs ol;
int main(int argc, char **argv) {
    ol.getLcs();
    return 0;
}
