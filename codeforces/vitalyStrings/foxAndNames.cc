//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <queue>



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
        void start() {
            string s, t;
            cin >> s >> t;
            if ( s == t ) {
                cout << "No such string\n";
            } else {
                string res;
                bool found = false;
                REP (i, s.size()) {
                    if (s[i] == t[i] || found) {
                        res += s[i];
                    } else {
                        res += (s[i] + 1);
                        found = true;
                    }
                }
                if (res != t) {
                    cout << res << "\n";
                } else {
                    cout << "No such string\n";
                }
            }
        }    

};

foxAndDots t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
