#include<bits/stdc++.h>

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
        int e2e[SZ][SZ]l
        bool isVertexUsed[SZ];
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
            if ( k < 10 ) res = '0' + k;
            if ( k >= 10 && k < 36) res = 'A' + k - 10;
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
            memset(isVertexUsed, 0, sizeof(bool) * SZ);
            memset(e2e, 0, sizeof(int) * SZ * SZ);
            cin >> N;
            REP (i, N) {
                scanf("%s\n", buff);
                string t(buff);
                int i1, i2;
                adjMatrix[i1 = getHash(t)][ i2 = getHash(t.substr(1))]++;
                isVertexUsed[i1] = isVertexUsed[i2] = true;
            }
            vector<PI> odd;
            for (int i = 0; i < SZ; i++) {
                int indegree = 0, outdegree = 0;
                for (int j = 0; j < SZ; j++) {
                    if (adjMatrix[i][j] > 0) outdegree++;
                    if (adjMatrix[j][i] > 0) indegree++;
                }
                if (outdegree - indegree != 0) {
                    odd.push_back(make_pair(i, outdegree - indegree));
                }
            }
            if (odd.size() > 2 || odd.size() == 1) {
                cout << "NO\n";
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
            pair<bool, string> res  = doFleurysAlgo(startNode);
            if (!res.first) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                cout << res.second << "\n";
            }
        }    
        bool areVerticiesReachable(int startNode, vector<int> &v) {
            cout << "New DFS \n";
            bool visited[SZ];
            v.clear();
            memset(visited, 0,sizeof(bool) * SZ);
            stack<int> s;
            s.push(startNode);
            while (!s.empty()) {
                int t = s.top();
                s.pop();
                if (visited[t]) continue;
                cout << "Getting node out of stack = "  << t  << " name= " << getString(t) << "\n";
                visited[t] = true;
                v.push_back(t);
                for (int i = 0 ; i < SZ; i++) {
                    if (adjMatrix[t][i] > 0) s.push(i);
                }
            }
            REP (i, SZ) {
                if (visited[i] != isVertexUsed[i]) return false;
            }
            return true;
        }
        /*
        pair<bool, string> doFleurysAlgo(int startNode) {
            vector<int> v;
            vector<int> order;
            string res;
            while (true) {
                bool canConnect = false;
                int last = -1;
                for (int i = 0 ; i < SZ; i++) {
                    if (adjMatrix[startNode][i] > 0) {
                        last = i;
                        adjMatrix[startNode][i]--;
                        if (areVerticiesReachable(startNode, v)) {
                            canConnect = true;
                            isVertexUsed[startNode] = false;
                            order.push_back(startNode);
                            startNode = i;
                            break;
                        } else {
                            adjMatrix[startNode][i]++;
                        }
                    }
                }
                if (!canConnect) {
                    isVertexUsed[startNode] = false;
                    if (last != -1) {
                        adjMatrix[startNode][last] = 0;
                        order.push_back(startNode);
                        startNode = last;
                    } else {
                        order.push_back(startNode);
                        break;
                    }
                } 
            }
            //Do a final dfs.
            //bool ans = areVerticiesReachable(startNode, v);
            bool ans = true;
            for (int i = 0 ; i < SZ; i++) {
                if (isVertexUsed[i] == true) {
                    ans = false;
                    break;
                }
            }
            if (ans) {
                REP(i, order.size()) {
                    cout << "Key = " << order[i] << " Eq string = " << getString(order[i]) << " \n";
                    if (res.empty()) {
                        res = getString(order[i]);
                    } else {
                        res = res.substr(0, res.size() - 1) + getString(order[i]);
                    }
                } 
            }
            return make_pair(ans, res);
        }
        */
};

tanyaPassword t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
