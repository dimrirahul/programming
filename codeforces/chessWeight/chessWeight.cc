#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
class chessWeight {
    public:
        PI getWeight(int c) {
            PI res;
            //B is 1, w =2
            int d = 0;
            if (c > 'Z') {
                res.first = 1;
                d = c - 'a';
            } else {
                res.first = 2;
                d = c - 'A';
            }

            int p = 0;
            if (d == 'q' - 'a') {
                p = 9;
            } else if (d == 'r' - 'a') {
                p = 5;
            } else if (d == 'b' - 'a') {
                p = 3;
            } else if (d == 'n' - 'a') {
                p = 3;
            } else if (d == 'p' - 'a') {
                p = 1;
            } else {
                p = 0;
            }

            res.second = p;
            return res;
        }



        void start() {
            string s;
            int wc = 0, bc = 0;
            for (int i = 0; i < 8; i++) {
                cin >> s;
                for (int j = 0; j < 8; j++) {
                    PI p = getWeight(s[j]);
                    if (p.first == 1) {
                        bc += p.second;
                    } else {
                        wc += p.second;
                    }
                }
            }
            if (bc > wc) { cout << "Black\n";}
            else if (bc < wc) { cout << "White\n";}
            else { cout << "Draw\n";}
        }

};

chessWeight t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
