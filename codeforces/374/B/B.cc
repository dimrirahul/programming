#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <array>

using namespace std;
using VI = vector<int>;
using LL = long long;
using PI = pair<int, int>;
using MI = map<int, int>;

const int MX_LEN = 300;
struct A {
    void start() {
        array<int, MX_LEN> arr;
        arr.fill(0);
        int n, k; cin >> n >> k;
        int lastSz = 0;
        for (int i = 0; i <= n; i++) {
            string s; cin >> s;
            if ( i < n) arr[s.size()]++;
            else lastSz = s.size();
        }
        int m1 = 0, m2 = 0;
        int sum = 0;
        for (int i = 0; i < lastSz; i++) sum += arr[i];
        m1 = sum + ((sum/k) * 5) + 1;
        sum += arr[lastSz] - 1;
        m2 = sum + ((sum/k) * 5) + 1;
        cout << m1 << " " << m2 << "\n";
    }
};

A a;
int main() {
    a.start();
    return 0;
}
