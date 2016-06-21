#include <iostream>

using namespace std;
int main(int argc, char **argv) {
    int d, h, v, e;
    cin >> d >> h >> v >> e;


    double n1 = 22 * d * d *h;

    double d1 = (28 * v)  - (e * 22 * d * d);
    double res = n1/d1;


    cout.precision(20);
    if ( res < 0 || res > (10 * 10 * 10 * 10)) cout << "NO\n";
    else cout << "YES\n" << res << "\n";
}

