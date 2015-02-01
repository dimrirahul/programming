#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define CP(A) A = _A

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 63 * 63 + 63;
class tanyaPassword {
    public:
        int adjMatrix[SZ][SZ];
        int indegree[SZ];
        int outdegree[SZ];
        bool visited[SZ]; 
        int N;
        int getKey(char c) {
            int res;
            if (c >= '0' &&  c <= '9') res = c - '0';
            if (c >= 'A' && c <= 'Z') res = 10 + c - 'A';
            if (c >= 'a' && c <= 'z') res = 36 + c - 'a';
            return res;
        }
        int getHash(string s) {
            return 62 * getKey(s[0]) + getKey(s[1]);
        }
        char getChar(int k) {
            char res;
            if (k < 10) res = '0' + k;
            if (k >= 10 && k < 36) res = 'A' + k - 10;
            if (k >= 36) res = 'a' + k - 36;
            return res;
        }
        string getString(int key) {
            int c1 = key / 62;
            int c2 = key % 62;
            string res;
            res.append(1, (char)getChar(c1));
            res.append(1, (char)getChar(c2));
            return res;
        }
        void start() {
            char buff[16];
            memset(adjMatrix, 0, sizeof(int) * SZ * SZ);
            memset(indegree, 0, sizeof(int) * SZ);
            memset(outdegree, 0, sizeof(int) * SZ);
            memset(visited, 0, sizeof(int) * SZ);
            cin >> N;
            REP (i, N) {
                scanf("%s\n", buff);
                string t(buff);
                int i1, i2;
                adjMatrix[i1 = getHash(t)][i2 = getHash(t.substr(1))]++;
                indegree[i2]++;
                outdegree[i1]++;
            }
            vector<PI> odd;
            for (int i = 0; i < SZ; i++) {
                if (outdegree[i] - indegree[i] != 0) {
                    odd.push_back(make_pair(i, outdegree[i] - indegree[i]));
                }
            }
            if (odd.size() > 2 || odd.size() == 1) {
                cout << "NO\n";
                //if (odd.size() != 6) cout << "Odd size = " << odd.size() << "\n";
                return;
            }
            //We have a champion.
            int startNode;
            if (odd.size() != 0) {
                if (odd[0].second > 0) startNode = odd[0].first;
                else startNode = odd[1].first;
            } else {
                for (int i = 0; i < SZ; i++) {
                    startNode = -1;
                    for (int j = 0; j < SZ; j++) {
                        if (adjMatrix[i][j] > 0) {
                            startNode = i;
                            break;
                        }
                    }
                    if (startNode != -1) break;
                }
            }
            string res  = doFleurysAlgo(startNode);
            bool areComponentsConnected = true;
            REP (i, SZ) {
                if ((indegree[i] > 0 || outdegree[i] > 0) && visited[i] == false) {
                    areComponentsConnected = false;
                    break;
                }
            }
            if (areComponentsConnected) {
                cout << "YES\n";
            } else {
                cout << "NO";
            }
            cout << res << "\n";
        }
        string doFleurysAlgo(int currentNode) {
            string res;
            vector<int> v;
            stack<int> s;
            while (true) {
                bool found = false;
                REP (i, SZ) {
                    if (adjMatrix[currentNode][i] > 0) {
                        adjMatrix[currentNode][i]--;
                        s.push(currentNode);
                        found = true;
                        currentNode = i; 
                        break;
                    }
                }
                if (!found) {
                    v.push_back(currentNode);
                    if (s.empty()) break;
                    currentNode = s.top();
                    s.pop();
                }
            }
            reverse(ALL(v));
            REP (i, v.size()) {
                visited[v[i]] = true;
//                cout << "STRING = " << getString(v[i]) << "\n";
                if (res.empty()) {
                    res = getString(v[i]);
                } else {
                    res += getString(v[i])[1];
                }
            }
            return res;
        }
};

tanyaPassword t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
