#include <bits/stdc++.h>

using namespace std;
int hannoi(int n) {
    if (n == 1) return n;
    return 2 * hannoi(n-1) + 1;
}
int main(int argc, char **argv) {
    int n;
    cin >> n;
    cout << "Res = " << hannoi(n) << "\n";
    return 0;
}
