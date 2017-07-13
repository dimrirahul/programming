#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

const int MX_SIZE = ((int)1e4) * 5;
using UL = unsigned long long;
using LL = long long;
const bool dbg = true;

using BaseStore = int32_t;
using DoubleBaseStore = int64_t;
const int BaseStoreSize = 32;

using Store = array<BaseStore, MX_SIZE>;

struct BigInt {
    enum OpType { MULT, ADD};

    int len;
    Store store;
    int MX_BASE_NO;;


    void init() {
        len = 0;
        store.fill(0);
        BaseStore one = 1;
        MX_BASE_NO = (one << (BaseStoreSize - 1)) -1;
    }

    bool valid() {
        return len < MX_SIZE;
    }

    BigInt(int sval) {
        init();
        while (sval > 0) {
            store[len++] = sval % MX_BASE_NO;
            sval /= MX_BASE_NO;
        }
    }

    BigInt() {
        init();
    }

    void print() const {
        cout << "Length=" << len << " Value=[";
        printAns();
        cout << "]";
    }

    void printAns() const {
        for (int i = len -1 ; i >= 0; i--) cout << (store[i]) ;
    }

    pair<BaseStore, BaseStore> extractBits(DoubleBaseStore k) const {
        DoubleBaseStore q, r;
        q = k / MX_BASE_NO;
        r = k % MX_BASE_NO;

        BaseStore cq, cr;
        cq = (BaseStore)q;
        cr = (BaseStore)r;

        return make_pair(cq, cr);
    }

    pair<BaseStore, BaseStore> doOperaration(BaseStore c1, BaseStore c2, OpType op) const {
        DoubleBaseStore t = c1;

        if (op == MULT)
            t *= c2;
        else
            t += c2;

        return extractBits(t);
    }

    pair<BaseStore, BaseStore> multiplyTwoChunks(BaseStore c1, BaseStore c2) const {
        return doOperaration(c1, c2, MULT);
    }

    pair<BaseStore, BaseStore> addTwoChunks(BaseStore c1, BaseStore c2) const {
        return doOperaration(c1, c2, ADD);
    }

    void addChunk(BaseStore c) {
        store[len++] = c;
    }

    void fitChunksIntoStore(pair<BaseStore, BaseStore> pi, BaseStore& c, BigInt& res) const {
        pair<BaseStore, BaseStore> t = addTwoChunks(pi.second, c);
        pair<BaseStore, BaseStore> r = addTwoChunks(pi.first, t.first);
        res.addChunk(r.second);
        c = r.first;
    }

    BigInt add(const BigInt& o) const {
        BigInt res;
        BaseStore c = 0;
        for (int i = 0; i < max(len, o.len); i++) {
            BaseStore v1 = i >= len ? 0: store[i];
            BaseStore v2 = i >= o.len ? 0: o.store[i];
            pair<BaseStore, BaseStore> t1 = addTwoChunks(v1, v2);
            fitChunksIntoStore(t1, c, res);
        }

        if (c != 0) {
            res.addChunk(c);
        }
        return res;
    }


    BigInt multiplyOneLine(const BigInt& o, BaseStore d, map<BaseStore, BigInt>& cache) const {
        auto it = cache.find(d);
        if (it != cache.end())
            return it->second;

        BigInt res;
        BaseStore c = 0;
        for (int i = 0; i < o.len; i++) {
            pair<BaseStore, BaseStore> p = multiplyTwoChunks(o.store[i], d);
            fitChunksIntoStore(p, c, res);
        }
        if (c != 0)
            res.addChunk(c);

        cache.insert(make_pair(d, res));
        return res;
    }

    void shiftLeft(int k) {
        for (int i = len -1; i >= 0; i--)
            store[i + k] = store[i];

        for (int i = 0; i < k; i++)
            store[i] = 0;

        len += k;
    }

    BigInt multiply(const BigInt& o) const {
        map<BaseStore, BigInt> cache;
        BigInt res;
        for (int i = 0; i < len; i++) {
            BigInt t = multiplyOneLine(o, store[i], cache);
            t.shiftLeft(i);
            res = res.add(t);
        }
        return res;
    }

    BigInt sq() const {
        BigInt cp = *this;
        return multiply(cp);
    }
};

BigInt dp[3];

void addTest() {
    BigInt b;
    BigInt b1(b.MX_BASE_NO);
    BigInt b2(b.MX_BASE_NO);
    BigInt s = b1.add(b2);
    cout << "Sum=";
    s.print();
    cout << "\n";
}
int main() {
    addTest();
    return 0;
    int t1, t2;
    int n;
    cin >> t1 >> t2 >> n;
    dp[1] = BigInt(t1);
    dp[2] = BigInt(t2);

    for (int i = 3; i <= n ; i++) {
        dp[i % 3] = dp[(i-2) % 3].add(dp[(i-1) % 3].sq());
        if (dbg) {
            cout << "i-2th term=";
            dp[(i-2) %3].print();
            cout << "\ni-ith term=";
            dp[(i-1) % 3].print();
            cout << "\nith term=";
            dp[i % 3].print();
            cout << "\n";
        }

    }
    dp[n%3].print();
    cout << "\n";

    return 0;
}
