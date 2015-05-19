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
class A {
public:

    set <int> s1;
    vector <int> posV;
    void start() {
        int t; cin >> t;
        string s;
        cin >> s;
        REP(i, s.size()) {
            if (s1.count(s[i]) == 0) {
                posV.push_back(i);
                s1.insert(s[i]);
            }
        }
        if (s1.size() < t) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int startPos = 0;
            int printed = 0;
            for (int i = 1; i < posV.size(); i++) {
                if (printed == t - 1) {
                    cout << s.substr(startPos) << "\n";
                    return;
                } else {
                    cout << s.substr(startPos, posV[i] - startPos) << "\n";
                    printed++;
                    startPos = posV[i];
                }
            }
            cout << s.substr(startPos) << "\n";
        }
    }    
};

A t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
