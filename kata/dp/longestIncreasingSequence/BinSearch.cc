#include <bits/stdc++.h>

using namespace std;
using VI = vector<int>;
using SI = set<int>;


struct BinSearch {
    int find(const VI& inp, int key) {
        int start = 0, end = inp.size();
        int res = -1;
        while (start < end) {
            int mid = (start + end)/2;
            if (inp[mid] == key) {
                res = mid;
                break;
            } else if (inp[mid] > key) {
                end = mid;
            } else {
                start = mid+1;
            }
        }
        return res;
    }
    int find2(const VI& inp, int key) {
        int l = 0, h = inp.size();
        while (l < h) {
            auto m = (l + h)/2;
            if (inp[m] == key) {
                return m;
            } else if (inp[m] > key) {
                h = m;
            } else {
                l = m+1;
            }
        }
        return -1;
    }
};

BinSearch binSearch;
const int SZ = 1000 - 1;
const int RANGE = (int)1e8;
int main(int argc, char **argv) {
    SI s;
    while (s.size() < SZ) {
        s.insert(random() % RANGE);
    }
    VI v;
    v.insert(end(v), begin(s), end(s));
    for (auto& i: s) {
        VI::iterator it = lower_bound(begin(v), end(v), i);
        int pos = it - v.begin();
        int p1 = binSearch.find2(v, i);
        if (p1 != pos) {
            cout << "Mismatch";
            cout << "Input\n";
            for (auto &j: v) cout << j << " ";
            cout << "\n Iterrator gave:" << pos << " You gave: " << p1 << "\n"; 
            break;
        }
    }
}




