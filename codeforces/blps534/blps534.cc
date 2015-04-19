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
const int SZ = (2 * 1e5) + 10;
const bool dbg = false;
class blps534 {
public:
    int N, M;
    int orig[SZ], mod[SZ], dist[SZ];

    void setZero(int (&a)[SZ]) {
        memset(a, 0, sizeof(int) * SZ);
    }
    int getLoops() {
        int res = 0;
        while ( res * (N - 1) * 2 < M) res++;
        res--;
        return res;
    }
    void updateMod(int loops) {
        REP(i, 1 + N) {
            if (i == 0) continue;
            if (i == 1 || i == N) {
                mod[i] = orig[i] - loops;
            } else {
                mod[i] = orig[i] - (2 * loops);
            }
        }
    }
    LL getLastIterDist() {
        int start = -1, end = -1;
        if (mod[1] == 0 && mod[N] == 0) {
            REP (i, N+1) {
                if (start == -1 && mod[i] > 0) start = i;
                if (start > 0 && mod[i] > 0) end = i;
            }
            if (dbg) printf("Case 1, start=%d, end=%d\n", start, end);
            return (LL)dist[end] - dist[start];
        } else if (mod[1] == 0 && mod[N] == 1) {
            int pos = N-1;
            LL res = 0;
            while (mod[pos] > 0 && pos >= 1) {
                if (mod[pos] == 2) res += 2 * (dist[pos+1] - dist[pos]);
                if (mod[pos] == 1) res += (dist[pos+1] - dist[pos]);
                if (mod[pos] == 0) break;
                pos--;
            }
            if (dbg) cout << "Case 2 res = " << res << "\n"; 
            return res;
        } else if (mod[1] == 1 && mod[N] == 0) {
            int pos = 2;
            LL res = 0;
            while(mod[pos] > 0 && pos < N) {
                if (mod[pos] == 2) res += 2 * (dist[pos] - dist[pos-1]);
                if (mod[pos] == 1) res += (dist[pos] - dist[pos-1]);
                if (mod[pos] == 0) break;
                pos++;
            }
            if (dbg) cout << "Case 3 res = " << res << "\n"; 
            return res;
        } else {
            int pos = 2;
            while (pos < N && mod[pos] == 2) pos++;
            start = pos -1;
            while (pos < N && mod[pos] == 1) pos++;
            end = pos ;
            if (dbg) printf("Case 4, start=%d, end=%d\n", start, end);
            return 2 * ((LL)dist[N] - dist[1]) - (dist[end] - dist[start]);
        }
    }
    bool isUniq() {
        bool notUniq = mod[1] == 1 && mod[N] == 1;
        for (int i = 2; i < N && notUniq; i++) {
            if (mod[i] != 2 ) notUniq = false;
        }
        return !notUniq;
    }
    bool areSegmentsEqual() {
        int d = dist[2] - dist[1];
        for (int i = 1; i < N; i++) {
            if (dist[i+1] - dist[i] != d) return false;
        }
        return true;
    }
    void printDbg() {
        cout << "OA\n";
        REP (i, N+1) cout << orig[i] << " ";
        cout << "\n MOD A\n";
        REP (i, N+1) cout << mod[i] << " ";
        cout << "\n DIST A\n";
        REP (i, N+1) cout << dist[i] << " ";
        cout << "\n";
    }
    void start() {
        setZero(orig);
        setZero(mod);
        setZero(dist);
        cin >> N;
        REP(i, N) {
            cin >> dist[i+1];
        }
        cin >> M;
        REP(i, M) {
            int t; cin >> t;
            orig[t]++;
        }
        //if (M == 1) {cout << "0\n"; return;}
        int loops = getLoops();
        if (dbg) cout << "loops = " << loops << "\n";
        updateMod(loops);
        if (dbg) printDbg();
        if (!isUniq() && !areSegmentsEqual()) {
            cout << "-1\n";
            return;
        }
        LL res = (LL)loops * (dist[N] - dist[1]);
        LL ed = getLastIterDist();
        cout << 2 * res + ed << "\n";
    }    
};

blps534 t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
