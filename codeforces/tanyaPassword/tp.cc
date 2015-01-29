//#include<bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <stack>
#include <unordered_map>

using namespace std;
const int BUF_SZ = 4;
const int KEY_SZ = 63;
class Triple {
    public:
        int t1, t2, t3;
        Triple(int _t1, int _t2, int _t3) {
            t1 = _t1;
            t2 = _t2;
            t3 = _t3;
        }
        Triple() {
            t1 = t2 = t3 = -1;
        }
        bool operator==(Triple other) const {
            return t1 == other.t1 && t2 == other.t2 && t3 == other.t3;
        }

        bool operator!=(Triple other) const {
            return !(*this == other);
        }
};
class Node {
    public:
        string v;
        bool visited;
        Triple t;
        Node(string _v) {
            v = _v;
            visited = false;
        }
};
class Password {
    public:
        char buff[BUF_SZ];
        int N;
        vector<Node> adjMatrix[KEY_SZ][KEY_SZ];
        int getKeyDigit(char c) {
            if (c >= '0' && c <= '9') return c - '0';
            if (c >= 'A' && c <= 'Z') return c + 10 - 'A';
            return c + 36 - 'a';
        }
        void start() {
            cin >> N;
            string res;
            bool done = false;
            for (int i = 0; i < N; i++) {
                scanf("%s\n", buff);
                adjMatrix[getKeyDigit(buff[0])][getKeyDigit(buff[1])].push_back(Node(string(buff)));
                if (N == 1) {
                    res = string(buff);
                    done = true;
                }
            }
            if (!done) res = doDfs();
            if (!res.empty()) {
                cout << "YES\n";
                cout << res << "\n";
            } else {
                cout << "NO\n";
            }
        }

        string doWalkBack(Triple src, Triple dest) {
            string res;
            int count = 0;
            vector <string> v;
            while (src != dest) {
                count++;
                v.push_back(adjMatrix[src.t1][src.t2][src.t3].v);
                src = adjMatrix[src.t1][src.t2][src.t3].t;
            }
            v.push_back(adjMatrix[dest.t1][dest.t2][dest.t3].v);
            if (count == N - 1) {
                reverse(v.begin(), v.end());
                res += v[0];
                for (int i = 1; i < v.size(); i++) {
                    res.append(1, v[i][2]);
                }
            }
            return res;
        }

        void printNode(Triple t) {
            printf("Index=[%d, %d, %d] visited=%d string=%s\n", t.t1, t.t2, t.t3, adjMatrix[t.t1][t.t2][t.t3].visited, adjMatrix[t.t1][t.t2][t.t3].v.c_str());
        }

        string doDfs() {
            stack<Triple> s;
            for (int i = 0; i < KEY_SZ; i++) {
                for (int j = 0; j < KEY_SZ; j++) {
                    for (int k = 0; k < adjMatrix[i][j].size(); k++) {
                        if (!adjMatrix[i][j][k].visited) {
                            s.push(Triple(i, j, k));
                            Triple t(0, 0, 0);
                            while (!s.empty()) {
                                Triple t1 = s.top();
                                s.pop();
                                if (adjMatrix[t1.t1][t1.t2][t1.t3].visited) continue;
                                t = t1;
                                printNode(t);
                                adjMatrix[t.t1][t.t2][t.t3].visited = true;
                                int k1, k2;
                                k1 = getKeyDigit(adjMatrix[t.t1][t.t2][t.t3].v[1]);
                                k2 = getKeyDigit(adjMatrix[t.t1][t.t2][t.t3].v[2]);
                                for (int l = 0; l < adjMatrix[k1][k2].size(); l++) {
                                    if (!adjMatrix[k1][k2][l].visited) {
                                        s.push(Triple(k1, k2, l));
                                        adjMatrix[k1][k2][l].t = t; 
                                    }
                                }

                            }
                            //see if we can walk back to parent (i, j, k)
                            string p = doWalkBack(t, Triple(i, j, k));
                            if (!p.empty()) {
                                return p;
                            }
                        }
                    }
                }
            }
            string p;
            return p;
        }
};

Password t;
int main(int argc, char **Argv) {
    t.start();
    return 0;

}
