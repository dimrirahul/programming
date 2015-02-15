#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int SZ = 1001;
const int MAX = 90000;
class RMQ {
    public:
        int dp[SZ][SZ];
        vector <int> v;
        int N;
        void init() {
            for (int i = 0;i < SZ; i++) {
                for (int j = 0; j < SZ; j++) {
                    dp[i][j] = MAX;
                }
            }
        }
        void start(vector<int>& v1) {
            init();
            v= v1;
            for (int i = 0; i < v.size(); i++) {
                for (int j = i ; j < v.size(); j++) {
                    if (j == i) {
                        dp[i][j] = v[i];
                    } else {
                        dp[i][j] = min(dp[i][j-1], v[j]);
                    }
                }
            }
        }

        void printDp() {
            for (int i = 0; i < v.size(); i++) {
                for (int j = 0; j < v.size(); j++) {
                    if (dp[i][j] == MAX) {
                        cout << "X ";
                    } else {
                        cout << dp[i][j] << " ";
                    }
                }
                cout << "\n";
            }
        }
        int query(int x, int y) {
            return dp[x][y];
        }
};

class SparseTable : public RMQ {
    public:

        void start(vector<int>& v1) {
            v = v1;
            init();
            N = v.size();
            for (int i = 0; i < N; i++) {
                dp[i][0] = v[i];
                int exp = 1;
                while (true) {
                    int start = (1 << (exp -1)) + i;
                    int end = min (N, (1 << (exp)) + i);
                    for (int k = start; k < end; k++) {
                        dp[i][exp] = min( dp[i][exp], min(dp[i][exp -1], v[k]) );
                    }
                    exp++;
                    if (end == N) break;
                }
            }
        }
};

vector<int> getInput() {
    vector <int> res;
    int t;
    while (cin >> t) res.push_back(t);
    return res;
}
SparseTable rmq;

int main(int argc, char **argv) {
    vector<int> v = getInput();
    rmq.start(v);
    rmq.printDp();
    return 0;
}
