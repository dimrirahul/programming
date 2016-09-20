#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>

using namespace std;
using VI = vector<int>;
using LL = long long;
using PI = pair<int, int>;
using MI = map<int, int>;
using LI = map<LL, int>;

const int BSET_SIZE = 19;
struct Key {
    Key(string s) {
        bset = bitset<BSET_SIZE>(s);
    }
    bitset<BSET_SIZE> bset;

    bool operator<(const Key& o) const { return bset.to_ullong()  < o.bset.to_ullong(); }
};

struct Query {
    enum eQtype {
        eAdd, eDel, eUpdate
    };

    eQtype qtype;
    string qString;
    LL val;

    void read() {
        char c; cin >> c;
        if (c == '+') qtype = eAdd;
        else if (c == '-') qtype = eDel;
        else qtype = eUpdate;

        if (qtype == eAdd || qtype == eDel) cin >> val;
        else cin >> qString;

    }

    Key getValAsKey() const {
        LL t = val;
        string s;
        while (t > 0) {
            int rem = t % 2;
            t /= 10;
            s.push_back( (rem == 1 ? '1' : '0') );
        }
        reverse(s.begin(), s.end());
        return Key(s);
    }

    Key getQstringAsKey() const {
        return Key(qString);
    }
};

using Store = map<Key, int>;
struct A {

    Store lookUp;
    void start() {
        vector<Query> queries;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            Query q;
            q.read();
            queries.push_back(q);
            if (q.qtype == Query::eUpdate) {
                Key k(q.qString);
                if (lookUp.find(k) != lookUp.end()) continue;
                lookUp.insert(make_pair(k, 0));
            }
        }

        for (auto& it : queries) {
            if (it.qtype == Query::eAdd || it.qtype == Query::eDel) {
                auto it1 = lookUp.find(it.getValAsKey());
                if (it1 == lookUp.end()) continue;
                if (it.qtype == Query::eAdd) {
                    it1->second++;
                } else {
                    it1->second--;
                }
            } else {
                int& m = lookUp[it.getQstringAsKey()];
                cout << m << "\n";
            }
        }
    }
};

A a;
int main() {
    a.start();
    return 0;
}
