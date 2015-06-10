#include <iostream>
#include <vector>
#include <array>

using namespace std;

const size_t SZ = 10;
int main() {
    array<array <int, SZ>, SZ> a{};
    for (auto& i : a) {
        for (auto& j: i) {
            cout << j;
        }
        cout << "\n";
    }
    return 0;
}
