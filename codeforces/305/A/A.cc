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

    bool isPossible(string s, int k) {
        if (s.size() % k != 0) return false;
        int sz = s.size() / k;
        for (int i = 0; i < s.size()/sz; i++) {
            string t = s.substr(i * sz, sz);
            string t1 = t;
            reverse(t1.begin(), t1.end());
            if (t1 != t) return false;
        }
        return true;
    }
    void start() {
        string s;
        cin >> s;
        int k; cin >> k;
        if (isPossible(s, k)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }    
};

A t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
