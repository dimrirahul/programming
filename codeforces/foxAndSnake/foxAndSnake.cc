#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int  SZ = 51;
class foxAndSnake {
public:
    int R, C;
    char arr[SZ][SZ];
    void start() {
        cin >> R >> C;
        memset(arr, 0, sizeof(char) * SZ * SZ);
        int last = 1;
        for (int i = 0 ; i < R; i++) {
            for (int j = 0; j < C; j++) {
                arr[i][j] = '.';
                if ( i %2 == 0) arr[i][j] = '#';
                else {
                    if (last % 2 == 0) {
                        if (j == 0) arr[i][j] = '#';
                    } else {
                        if (j == C-1) arr[i][j] = '#';
                    }
                }
            }
            if (i % 2 == 1) last++;
        }
        REP (i, R) {
            printf("%s\n", arr[i]);
        }
    }    
};

foxAndSnake t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
