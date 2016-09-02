#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
#include <sstream>
#include <map>
using namespace std;

const bool dbg = true;

const int MAX_WIDTH = 500;
using IR = array<int, MAX_WIDTH>;
IR buffer[MAX_WIDTH];
map<int, IR> cache;

void resetBuffer() {
    for (int i = 0 ; i < MAX_WIDTH; i++) buffer[i].fill(0);
}

struct BigNum {
    void reset() {
        curr.fill(0);
    }

    BigNum() {
        reset();
    }

    BigNum(const BigNum& o) {
        valid = true;
        reset();
        curr = o.curr;
    }

    BigNum(int x) {
        valid = true;
        reset();
        stringstream ss;
        ss << x;
        string s = ss.str();
        int pos = MAX_WIDTH -1;
        reverse(s.begin(), s.end());
        for (auto& it : s) {
            curr[pos--] = it - '0';
            if (pos < 0) break;
        }
    }

    void add(const BigNum& o) {
        valid = true;
        add(o.curr);
    }

    void add(const IR& other) {
        int pos = MAX_WIDTH - 1;
        int s = 0, c = 0;
        IR temp;
        temp.fill(0);
        while (pos >= 0) {
            s = curr[pos] + other[pos] + c;
            c = s / 10;
            s %= 10;
            temp[pos--] = s;
        }
        curr = temp;
    }

    void mult(int n, int shift) {
        IR temp;
        temp.fill(0);
        int pos;
        if (cache.find(n) != cache.end()) {
            temp = cache[n];
            if (dbg) cout << "Cache hit\n";
        } else {
            pos = MAX_WIDTH - 1;
            int s = 0, c = 0;
            while (pos >= 0) {
                s = curr[pos] * n + c;
                c = s / 10;
                s %= 10;
                temp[pos--] = s;
            }
            cache.insert(make_pair(n, temp));
        }
        pos = MAX_WIDTH - 1;
        while (pos >= 0 && (pos-shift) >= 0) {
            buffer[shift][pos - shift] = temp[pos];
            pos--;
        }
    }

    void mult(const BigNum& other) {
        resetBuffer();
        cache.clear();
        valid = true;
        for (int i = 0; i < MAX_WIDTH; i++) {
            int pos = MAX_WIDTH - 1 -i;
            if (pos < 0) break;
            mult(other.curr[pos], i);
        }
        curr.fill(0);
        for (int i = 0; i < MAX_WIDTH; i++) {
            add(buffer[i]);
        }
    }

    string print() {
        bool beginPrinting = false;
        stringstream ss;
        for (int i = 0; i < MAX_WIDTH; i++) {
            if (curr[i] != 0) beginPrinting = true;
            if (beginPrinting) ss << curr[i];
        }
        return ss.str();
    }

    bool isValid() { return valid; }
    IR curr;
    bool valid = false;

};



array<BigNum, MAX_WIDTH> res;
BigNum t1, t2, t3;
int a, b, x;
BigNum getN(int n) {
    if (n == 1) return BigNum(a);
    if (n == 2) return BigNum(b);
    if (res[n].isValid()) return res[n];
    t1.reset(); t2.reset(); t3.reset();
    t1 = getN(n-1);
    t2 = getN(n-1);
    t1.mult(t2);
    t3 = getN(n-2);
    t1.add(t3);
    res[n] = t1;
    if (dbg) cout << "Result for n: " << n << " = " << res[n].print() << "\n";
    return res[n];
}

int main() {
    cin >> a >> b >> x;
    cout << getN(x).print() << "\n";
    return 0;
}

