#include <iostream>


using namespace std;

bool isValid(int x) {
    return x <= 8 && x >= 1;
}

bool isValid(int c, int d) {
    return isValid(c) && isValid(d);
}

int main() {
    int c, d;
    char p;
    cin >> p >> d;
    c = p - 'a';
    c++;
    int res = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (isValid(c + i, d + j)) res++;
        }
    }
    res--;
    cout << res << "\n";
    return 0;
}
