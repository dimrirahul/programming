#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const bool dbg = true;

vector<int> findValues(const vector<int>& v) {
    vector<int> t {v[0], v[1], v[2]};
    int l1, l2, l3;
    int l1p = distance(t.begin(), min_element(t.begin(), t.end()));
    int l3p = distance(t.begin(), max_element(t.begin(), t.end()));
    l1 = t[l1p];
    l3 = t[l3p];
    for (int i = 0; i < t.size(); i++) {
        if (i == l1p || i == l3p) continue;
        l2 = t[i];
        break;
    }
    auto f = [&l1, &l2, &l3](int x) {
        if (dbg) {
            cout << "l1=" << l1 << " l2=" << l2 << " l3=" << l3;
            cout << "\n";
        }
        if (x <= l1) {
            l3 = l2;
            l2 = l1;
            l1 = x;
        } else if (x <= l2) {
            l3 = l2;
            l2 = x;
        } else if (x < l3) {
            l3 = x;
        }
    };
    if (dbg) cout << "\n";

    for_each(v.begin() + 3, v.end(), f);
    return vector<int> {l1, l2, l3};

}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    vector<int> v;
    v.reserve(t);
    for (int i = 0; i < t; i++) {
        int u; cin >> u;
        v.push_back(u);
    }
    auto lowestElements = findValues(v);
    if (dbg) {
        cout << "Lowest elements are: ";
        for (auto it : lowestElements) {
            cout <<  it << " ";
        }
        cout << "\n";
    }
    vector<int> counts {0, 0, 0};
    for_each(
            v.begin(), v.end(),
            [&counts, lowestElements] (int x) {
                for (int i = 0; i < 3; i++) {
                    if (x == lowestElements[i]) counts[i]++;
                }
            }
        );
    if (dbg) {
        cout << "Lowest with counts elements are: ";
        for (int i = 0; i < lowestElements.size(); i++) {
            cout <<  "lowest element[" << i << "]  has count " << counts[i] << "\n";
        }
        cout << "\n";
    }

    long long res = 1;
    if (lowestElements[0] == lowestElements[1] && lowestElements[1] == lowestElements[2]) {
        if (dbg) cout << "All are equal\n";
        res *= counts[0];
        res = ((res) * (res -1) * (res -2)) / 6;
    } else if (lowestElements[0] == lowestElements[1]) {
        if (dbg) cout << "0 and 1 are equal\n";
        res *= counts[0];
        if (dbg) cout << "Count=" << res << "\n";
        res = ((res) * (res -1)) / 2;
        if (dbg) cout << "Count=" << res << "\n";
        res *= counts[2];
        if (dbg) cout << "Count=" << res << "\n";
    } else if (lowestElements[0] == lowestElements[2]) {
        if (dbg) cout << "0 and 2 are equal\n";
        res *= counts[0];
        res = ((res) * (res -1)) / 2;
        res *= counts[1];
    } else if (lowestElements[1] == lowestElements[2]) {
        if (dbg) cout << "1 and 2 are equal\n";
        res *= counts[2];
        res = ((res) * (res -1)) / 2;
        res *= counts[0];
    } else {
        if (dbg) cout << "None are equal\n";
        res *= counts[0];
        res *= counts[1];
        res *= counts[2];
    }
    cout << res << "\n";
    return 0;
}
