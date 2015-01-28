#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 100001;
class antonCurrency {
public:
    char buff[SZ];
    void start() {
        scanf("%s\n", buff);
        int len = strlen(buff);
        int far, close;
        far = close = -1; 
        for (int i = 0; i < len; i++) {
            if ((buff[i] - '0') % 2 == 0) {
                if (far == -1 && buff[i] < buff[len -1]) far = i;
                if (buff[i] > buff[len -1]) close = i;
            }
        }

        if (far == -1 && close == -1) { cout << "-1\n"; return; }
        if (far != -1) swap(buff[far], buff[len-1]);
        else swap(buff[close], buff[len-1]);
        printf("%s\n", buff);
    }    
};

antonCurrency t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
