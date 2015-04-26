//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <queue>
#include <cstring>



#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 26;

class foxAndDots {
    public:
        int s[SZ][2];
        int t[SZ][2];

        void updateHash(string str, int (&arr)[SZ][2]) {
            memset(arr, 0, sizeof(int) * SZ * 2);
            REP (i, str.size()) {
                if (str[i] <= 'Z') {
                    arr[str[i] - 'A'][0]++;
                } else {
                    arr[str[i] - 'a'][1]++;
                }
            }
        }
        void start() {
            string s1, t1;
            cin >> s1 >> t1;
            updateHash(s1, s);
            updateHash(t1, t);
            int yc = 0, wc = 0;
            REP (i, SZ) {
                REP (j, 2) {
                    int t2 = min(s[i][j], t[i][j]);
                    s[i][j] -= t2;
                    t[i][j] -= t2;
                    yc += t2;
                }
                REP (j, 2) {
                    int j1 = (j+1) % 2;
                    int t2 = min(s[i][j], t[i][j1]);
                    s[i][j] -= t2;
                    t[i][j1] -= t2;
                    wc += t2;
                }
                
            }
            cout << yc << " " << wc << "\n"; 
        }    

};

foxAndDots t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
