//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <queue>



#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 26;

class foxAndDots {
    public:
        PI matrix[SZ][SZ];
        int N;
        void init() {
            REP (i, SZ) {
                REP (j, SZ) {
                    matrix[i][j] = make_pair(-1, 0);
                }
            }
        }

        pair <bool, int> addEdge(string p, string c) {
            //cout << "Add Edge for " << p << " " << c << "\n";
            int pos = -1;
            REP (i, min(p.size(), c.size())) {
                if (p[i] != c[i]) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                if (c.size() < p.size()) return make_pair(false, pos);
                if (c.size() >= p.size()) return make_pair(true, -1);
            }
            matrix[p[pos] - 'a'][c[pos] - 'a'] = make_pair(-1, 1);
            //cout << p << " " << c << " pos =" << pos << "\n";
            //cout << "P[pos]" <<  p[pos] << "\n";
            return make_pair(true, p[pos]);
        }
        string getOrder(int startV) {
            string res;
            queue<int> q;
            q.push(startV);
            set <int> visited;
            while (!q.empty()) {
                int n = q.front();
                q.pop();
                if (visited.count(n) > 0) return string("");
                visited.insert(n);
                res += (char)(n + 'a');
             //   cout << "n=" << n << "\n";
                for (int i = 0; i < SZ; i++) {
                    if (matrix[n][i].second == 1) {
                        q.push(i);
                    }
                }
            }
            return res;
        }
        string start() {
            init();
            cin >> N;
            string prev, curr;
            cin >> prev;
            int startVertex = -1;
            REP (i, N-1) {
                cin >> curr;
                pair <bool , int> p = addEdge(prev, curr);
                if (!p.first) return string("Impossible");
                if (startVertex == -1) startVertex = p.second;
                prev = curr;
            }
            startVertex -= 'a';
            //cout << "StartVertex = " << (char) ('a' + startVertex) << "\n";
            string order;
            if (startVertex >= 0) {
                order = getOrder(startVertex);
                if (order == string("")) return "Impossible";
            }
            //cout << "Order = " << order << "\n";
            string res;
            REP (i, 26) {
                bool found = false;
                REP (j , order.size()) {
                    if (order[j] == 'a' + i) {
                        found = true;
                        break;
                    }
                }
                if (!found) res += 'a' + i;
            }
            res.insert(res.end(), ALL(order));
            return res;
        }    

};

foxAndDots t;

int main(int argc, char **argv) {
    cout << t.start() << "\n";
    return 0;
}
