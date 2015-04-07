#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FORU(I,A,B) for(unsigned int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define REPU(I,N)   FORU(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
class kingOfTheives {
public:

    void start() {
        int u;
        cin >> u;
        string s;
        cin >> s;
        bool res = false;
        for (int i = 0; i < s.size() && !res; i++) {
            for (int j = 1; j < (s.size()/5 + 1) && !res; j++) {
                bool noPit = true;
                int platformCount = 0;
                for (int k = 0; k < 5 && (i +j * k < s.size()); k++) {
                    //cout << "[" << i << "," << j << "," << k << "] " << s[i + k * j] << "\n";
                    if (s[i + k * j] == '.') {
                        noPit = false;
                        break;
                    } else {
                        platformCount++;
                    }
                }
                res = noPit && platformCount == 5;
            }
        }
        cout << (res ? "yes": "no") << "\n";

    }    
};

kingOfTheives t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
