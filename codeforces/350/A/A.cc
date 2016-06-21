#include <iostream>

using namespace std;
int main(int argc, char **argv) {
    int d;
    cin >> d;
    int w = d / 7;
    int rem = d % 7;
    int maxDays, minDays;
    maxDays = minDays = 2 * w;
    if (rem <= 2) {
        maxDays += rem;
    } else {
        maxDays += 2;
    }

    if (rem >= 5) {
        minDays += rem - 5;
    }

    cout << minDays << " " << maxDays << "\n";
    return 0;
}
