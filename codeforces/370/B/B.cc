#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

using VI = vector<int>;
using SI = set<int>;


const bool dbg = !true;
int getVal(int u, int d, int l, int r) {
    int sum = u + d + l + r;
    if (sum % 2 == 1) return -1;
    int hz = l + r;
    int ve = u + d;
    int res = 0;
    if ( hz % 2 == 1) {
        res++;
        if ( hz < ve) {
            ve--; hz++;
            int& t1 = (u < d) ? d : u;
            t1--;

            int& t2 = (l < r) ? l : r;
            t2++;
        } else {
            ve++; hz--;
            int& t1 = (u < d) ? u : d;
            t1++;

            int& t2 = (l < r) ? r : l;
            t2--;
        }
    }

    res += max(u, d) - hz/2;
    res += max(l, r) - ve/2;
    return res;
}


int main() {
    int u = 0, d = 0, l = 0, r = 0;
    string s;
    cin >> s;
    for (auto c : s) {
        if (dbg) cout << "C=" << c << " ";
        if (c == 'U') u++;
        else if (c == 'D') d++;
        else if (c == 'L') l++;
        else if (c == 'R') r++;
    }
    if (dbg) cout <<"U=" <<  u << " D=" << d << " L=" << l << " R=" << r << "\n";
    cout << getVal(u, d, l, r);
    return 0;
}
