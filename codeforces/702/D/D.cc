#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>


using namespace std;

const double ep = 1e-6;

const bool dbg = true;

bool isPossible(double t, int n, int l, int v1, int v2, int k) {
    int p = n/k;
    if (n > p * k) p++;
    double pos = 0;
    double t1 = t;
    double l1 = l;
    if (l1 / v1 <= t) return true;
    if (dbg) cout << "Solving t=" << t << " n=" << n << " l=" << l << " v1=" << v1 << " v2=" << v2 << " k=" << k << " p=" << p << "\n";
    for (int i = 0; i < p; i++) {
        double num = (double)l - pos - (t1 * v1);
        double den = (v2 - v1);
        if (dbg) cout << "num=" << num << " l=" << l << " pos=" << pos << " t1=" << t1 << " v1=" << v1 << "\n";
        if (num < 0) {
            if (dbg) cout << "num is less than 0 returning \n";
            return false;
        }
        double t2 = num/den;
        double distTravelledByNextGroup = t2 * v1;
        double d2 = t2 * v2 - distTravelledByNextGroup;
        double t3 = d2 / (v2 + v1);
        pos = (t3 + t2) * v1;
        t1 -= (t3 + t2);
    }

    return true;
}

int main() {
    int n, v1, v2, l, k;
    cin >> n >> l >> v1 >> v2 >> k;
    if (v2 <= v1) {
        double d = l;
        d /= v1;
        cout << d << "\n";
    }
    double start = 0;
    double end = (double)l / v1;
    end += 30;
    double res = end;
    while (abs(start - end) > ep) {
        double mid = (start + end)/2;
        if (isPossible(mid, n, l, v1, v2, k)) {
            res = min(res, mid);
            end = mid - ep;
        } else {
            start = mid + ep;
        }
    }
    cout << res << "\n";
    return 0;

}
