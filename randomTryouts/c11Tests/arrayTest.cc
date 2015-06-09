#include <iostream>
#include <vector>
#include <array>

using namespace std;

const int SZ = 10;
int main() {
    array <int, SZ>a;
    a.fill(0);
    for (auto i : a) {
        cout << a[i] << " ";
    }
    return 0;
}
