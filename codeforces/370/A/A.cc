#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

using VI = vector<int>;
using SI = set<int>;


const int MX_SZ = 100000 + 10;
int main() {
    int b[MX_SZ];
    int a[MX_SZ];
    for (int i = 0; i < MX_SZ; i++) b[i] = a[i] = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (i == n-1) b[i] = a[i];
        else b[i] = a[i] + a[i+1];
    }
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";
    return 0;
}
