#include <iostream>
#include <map>

using namespace std;

int main() {
    int ns, cv = 0, ch = 0, sum = 0;
    cin >> ns;
    for (int i = 0; i < ns; i++) {
        char c; cin >> c;
        int s = c - 'D';
        if (!s) {
            sum--;
        } else {
            sum++;
        }
        if (sum == 0) {
            if (!s) ch++;
            else cv++;
        }
    }
    cout << cv << "\n";
    return 0;
}
