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
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int hcf(int a, int b) {
    LL res = (LL) a * b;
    return (int) (res/gcd(a, b));
}

class omnomCandies {
public:

    map <int, LL> cache;
    int c, hr, hb, wr, wb;
    LL doDp(int w) {
        if (w < wr && w < wb) return 0;
        if (cache.count(w) > 0) return cache[w];
        //cout << "Solving for " << w << "\n";
        LL mx;
        if (w >= wr && w >= wb) {
             mx = max(hr + doDp(w - wr), hb + doDp(w - wb));
        } else {
            if ( wr == max(wr, wb)) {
                mx = ((LL) hb) * (w / wb);
            } else {
                mx = ((LL) hr) * (w / wr);
            }
        }
        cache[w] = mx;
        //cout << "Res = " << mx << "\n";
        return mx;
    }

    pair<LL, int> calcGreedy() {
        bool isRedLighter = ((LL) hr * wb) > ((LL) hb * wr);
        int optimalW = isRedLighter ? wr: wb;
        int optimalH = isRedLighter ? hr: hb;
        LL res = c;
        int hcfW = hcf(wr, wb);
        cout << "HCF=" << hcfW << "\n";
        res /= hcfW;
        cout << (isRedLighter ? "Red " : " Blue" ) << " is lighter\n"; 
        cout << "res = " << res << " hcfw= " << hcfW << " optimal h= " << optimalH << " optimalw= " << optimalW << "\n";
        int x = hcfW / optimalW;
        cout << "X=" << x << " prod= " << x * optimalW << "\n";
        res = res * optimalH * x;
        return make_pair(res, c % hcfW);
    }
    void start() {
        cin >> c >> hr >> hb >> wr >> wb;
        pair<LL, int> p = calcGreedy();
        LL res = p.first;
        c = p.second;
        int t1 = doDp(c);
        cout << "HCF op =  " << res << " DP = "<< t1 << "With W = " << c << "\n";
        res += doDp(c);
        cout << res << "\n";
    }    
};

omnomCandies t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
