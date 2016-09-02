#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


using VI = vector<int>;
using LL = long long;
using VL = vector<LL>;


const bool dbg = !true;

LL getD(VL& cumSum, VL& numbers, int r) {
    LL v1 = *cumSum.rbegin();
    if (dbg) cout << "r=" << r <<" sz=" << numbers.size() << "\n";
    int sz = numbers.size();
    int r2 = 2 * r;
    LL v2 = numbers[r] * (r2 - sz);
    LL v3 = 2 * cumSum[r-1];
    if (dbg) cout << "v1=" << v1 << " v2=" << v2 << " v3=" << v3 << "\n";
    return v1 + v2 - v3;
}

int main() {
    int n;
    cin >> n;
    VL numbers;

    for (int i = 0 ; i < n; i++) {
        int t; cin >> t;
        numbers.push_back(t);
    }

    sort(numbers.begin(), numbers.end());
    LL minNumber = *numbers.begin();

    if (dbg) cout << "Min Number=" << minNumber << "\n";

    VL cumSum;
    LL sum = 0;
    for (int i = 0 ; i < numbers.size(); i++) {
        numbers[i] -= minNumber;
        sum += numbers[i];
        cumSum.push_back(sum);
    }

    /*
    if (dbg) {
        cout << "Numbers:\n";
        for (auto it : numbers) cout << it << " ";
        cout << "\nCumSum:\n";
        for (auto it : cumSum) cout << it << " ";
        cout << "\n";
    }
    */

    int res = 0;
    LL minValue = sum;
    for (int i = 1 ; i < numbers.size(); i++) {
        LL d = getD(cumSum, numbers, i);
        if (dbg) cout << "MinValue= " << minValue << " index= " << i << " d=" << d << "\n";
        if (d < minValue) {
            minValue = d;
            res = i;
            if (dbg) cout << "Updated index to=" << res << "\n";
        }
    }
    cout << numbers[res] + minNumber << "\n";
    return 0;
}
