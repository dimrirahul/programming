#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
class Agame {
public:
    void start() {
        int n1, n2;
        cin >> n1 >> n2 ;
        printf("%s\n", n1 > n2 ? "First": "Second");
    }    
    void thisIsTheShit() {
    }
};

Agame t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
