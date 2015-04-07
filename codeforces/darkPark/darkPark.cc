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
class Triple {
    public:
        int l, r, p;
        Triple() {
            l = r = p = 0;
        }
        Triple(int _l, int _r, int _p) {
            l = _l; r = _r; p = _p;
        }
};

const int SZ = (1 << 11);
class darkPark {
public:
    Triple arr[SZ];
    int depth;
    map<int, int> cache;
    bool amRightChild(int id) {
        return id % 2 == 1;
    }
    void updateTree() {
        for (int i = (1 << (depth + 1)) - 1; i > 0; i--) {
            if (amRightChild(i)) {
                arr[i/2].r = arr[i].p + max(arr[i].l , arr[i].r);
            } else {
                arr[i/2].l = arr[i].p + max(arr[i].l , arr[i].r);
            }
        }
    }
    int processTree(int id) {
        if (arr[id].l == 0 && arr[id].r == 0) return 0;
        if (cache.count(id) > 0) return cache[id];
        int l = processTree(2 * id);
        int r = processTree(2 * id + 1);
        cache[id] = l + r + abs(arr[id].l - arr[id].r);
        return cache[id];
    }
    void start() {
        cin >> depth;
        for (int i = 0; i < (1 << (depth + 1)) -2; i++) {
            int t; cin >> t;
            arr[i+2].p = t;
        }
        updateTree();
        int res = processTree(1);
        cout << res << "\n";
    }    
};

darkPark t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
