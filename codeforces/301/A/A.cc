#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class A {
    public:
        void start() {
            string s1, s2;
            int n; cin >> n;
            cin >> s1 >> s2;
            long long res = 0;
            for (int i = 0; i < s1.size(); i++) {
                int d1 = (s1[i] - '0');
                int d2 = (s2[i] - '0');
                int l = min(d1, d2);
                int m = max(d1, d2);
                res += min (abs(m - l), abs(l + 10 - m));
            }
            cout << res << "\n";
        }
};

A a;
int main(int argc, char **Argv) {
    a.start();
    return 0;
}
