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

typedef pair<char, int> PCI;
typedef long long LL;
class errorCorrectSystem {
public:
    map< int, int > av[26];
    int L;
    string S, T;
    void start() {
        cin >> L;
        cin >> S;
        cin >> T;
        int ham = 0;
        REP(i, L) {
            if (S[i] != T[i]) {
                av[S[i] - 'a'][T[i] - 'a'] = i;
                ham++;
            }
        }
        bool found1 = false;
        bool found2 = false;
        int p1 = -2, p2 = -2;
        for (int i = 0; i < 26 && !found2; i++) {
            for (map<int, int>::const_iterator it = av[i].begin(); it != av[i].end() && !found2; it++) {
                if (av[it->first].count(i) > 0) {
                    found2 = true;
                    p1 = it->second;
                    p2 = av[it->first][i];
                } else {
                    map <int, int>::const_iterator it1 = av[it->first].begin();
                    if (it1 != av[it->first].end()) {
                        found1 = true;
                        p1 = it->second;
                        p2 = it1->second;
                    }
                }
            }
        }
        int sz = ham;
        if (found2) {
            sz -= 2;
        } else if (found1) {
            sz -= 1;
        }
            p1++; p2++;
        cout << sz << "\n" << p1 << " " << p2 << "\n";
    }    
};

errorCorrectSystem t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
