#include <bits/stdc++.h>

using namespace std;

const int NUM_NODES = (int) 5e5 + 10;
const int MAX_DEPTH = 22;
const int CHARS = 26;

struct D {
    int dp[NUM_NODES][MAX_DEPTH][CHARS];
    
    int _n, _m;
    void start() {
        cin >> _n >> _m;
        memset(dp, 0, sizeof(int) * NUM_NODES * MAX_DEPTH * CHARS);
        for (int i = 0; i < _m ; i++) cout << "Yes\n";
    }
        
};

D d;
int main(int argc, char **argv) {
    d.start();
    return 0;
}
