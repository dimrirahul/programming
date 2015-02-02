#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <unordered_map>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define CP(A) A = _A

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;
typedef unordered_map<int, VI> MVI;

typedef long long LL;
const int SZ = 63 * 63 + 63;
class tanyaPassword {
    public:
        MVI adjMatrix;
        int indegree[SZ];
        int outdegree[SZ];
        bool visited[SZ];
        unsigned int posV[SZ];
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

        bool checkFailed(vector<pair<int, int> > &odd) {
            if (odd.size() % 2 == 1 || odd.size() > 2) return true;
            if (odd.size() > 1 && (abs(odd[0].second) != 1 || abs(odd[1].second) != 1)) return true;
            return false;
        }
        void start() {
            char buff[16];
            memset(posV, 0, sizeof(int) * SZ);
            memset(indegree, 0, sizeof(int) * SZ);
            memset(outdegree, 0, sizeof(int) * SZ);
            memset(visited, 0, sizeof(bool) * SZ);
            cin >> N;
            REP (i, N) {
                scanf("%s\n", buff);
                string t(buff);
                int i1, i2;
                i1 = getHash(t);
                i2 = getHash(t.substr(1));
                if (adjMatrix.count(i1) == 0) {
                    VI t;
                    adjMatrix[i1] = t;
                }
                adjMatrix[i1].push_back(i2);
                indegree[i2]++;
                outdegree[i1]++;
            }
            vector<PI> odd;
            for (int i = 0; i < SZ; i++) {
                if (outdegree[i] - indegree[i] != 0) {
                    odd.push_back(make_pair(i, outdegree[i] - indegree[i]));
                }
            }
            if (checkFailed(odd)) {
                cout << "NO\n";
                return;
            }
            //We have a champion.
            int startNode = -1;
            if (odd.size() != 0) {
                if (odd[0].second > 0) startNode = odd[0].first;
                else startNode = odd[1].first;
            } else {
                for (MVI::const_iterator it = adjMatrix.begin(); it != adjMatrix.end() && startNode == -1; it++) {
                    if ((it->second).size() > 0) startNode = it->first;
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
                cout << res << "\n";
            } else {
                cout << "NO";
            }
        }
        string doFleurysAlgo(int currentNode) {
            string res;
            vector<int> v;
            stack<int> s;
            while (true) {
                bool found = false;
                if (adjMatrix[currentNode].size() > posV[currentNode]) {
                    int next = adjMatrix[currentNode][posV[currentNode]];
                    s.push(currentNode);
                    posV[currentNode]++;
                    currentNode = next;
                    found = true;
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
