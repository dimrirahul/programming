#include <vector>
#include <iostream>

using namespace std;
int main() {
    vector<int> v1 {40, 50};
    vector<int> v2 {10, 20};
    v1.insert(v1.begin(), v2.begin(), v2.end());
    for (auto it : v1) {
        cout << it << " ";
    }
    return 0;
}
