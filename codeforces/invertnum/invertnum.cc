#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
class invertnum {
public:

    void start() {
        string s;
        cin >>  s;
        REP (i , s.size()) {
            if (i == 0 && s[i] == '9') continue;
            int v = s[i] - '0';
            if (9 -v < v) {
                s[i] = 9 - v + '0';
            }
        }
        cout << s << "\n";
    }    
};

invertnum t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
