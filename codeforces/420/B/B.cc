#include <bits/stdc++.h>


using namespace std;
using VI = vector<int>;
using LL = long long;


struct A {
    int M, B;

    LL getBananas(LL x, LL y) {
        return ((x + 1) * (y + 1) * ( x + y)) / 2;
    }


    int getClosestX(int y) {
        return (B - y ) * M;
    }
    void start() {
        cin >> M >> B;
        LL res = (B * (B + 1)) / 2;
        for (int i = 0; i <= B; i++) {
            int x = getClosestX(i);
            res = max(res, getBananas(x, i));
        }
        cout << res << "\n";
    }
};

A a;
int main() {
    a.start();
    return 0;
}
