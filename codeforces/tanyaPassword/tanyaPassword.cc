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
        cin >> N;
        REP (i, N) {
            scanf("%s\n", buff);
            string t(buff);
            adjMatrix[getHash(t)][getHash(t.substr(1))]++;
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

    pair<bool, string> doFleurysAlgo(int startNode) {
        string res;
        stack<int> s;
        map<int, int> parent;
        parent[startNode] = -1;
        s.push(startNode);
        while (!s.empty()) {
            int t = s.top();
            s.pop();
            int p = parent[t];
            if (res.empty()) {
                res = getString(t);
            } else {
                res = res.substr(0, res.size() - 1) + getString(t);
            }
            cout << "RES = " << res << "\n";
            if (p != -1) adjMatrix[p][t]--;
            for (int i = 0; i < SZ; i++) {
                if (adjMatrix[t][i] > 0) {
                    parent[i] = t;
                    s.push(i);
                }
            }
        }
        // Check if there are still someedges left
        bool allComponentsConnected = true;
        REP (i, SZ) {
            REP(j, SZ) {
                if (adjMatrix[i][j] > 0) {
                    allComponentsConnected = false;
                    break;
                }
            }
        }

        return make_pair(allComponentsConnected, res);
    }
};

tanyaPassword t;

int main(int argc, char **argv) {
    t.start();
    return 0;
}
