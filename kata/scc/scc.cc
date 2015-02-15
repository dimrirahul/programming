#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

typedef pair <int , int > PI;
const int SZ = 101;
class Scc {
    public:
        bool mat[SZ][SZ];
        bool inStack[SZ];
        PI nodeInfo[SZ];
        stack <int> s;
        int N, id;
        int index = 0;
        void start() {
            memset(inStack, 0, sizeof(bool) * SZ);
            memset(mat, 0, sizeof(bool) * SZ *SZ);
            for (int i = 0; i < SZ; i++) nodeInfo[i] = make_pair(-1, -1);
            string inp;
            id = 0;
            while (cin >> inp) {
                N = inp.size();
                for (int i = 0; i < N; i++) {
                    if (inp[i] == '1') mat[id][i] = true;
                }
                id++;
            }
            for (int i = 0; i < N; i++) {
                if (nodeInfo[i].first == -1) addNode(i);
            }
        }

        void addNode(int n) {
            nodeInfo[n] = make_pair(index, index);
            index++;
            s.push(n);
            inStack[n] = true;
            for (int i = 0; i < N; i++) {
                if (mat[n][i]) {
                    if (nodeInfo[i].first == -1) {
                        addNode(i);
                        nodeInfo[n].second = min(nodeInfo[n].second, nodeInfo[i].second);
                    } else if (inStack[i]) {
                        nodeInfo[n].second = min(nodeInfo[n].second, nodeInfo[i].first);
                    }
                }
            }
            if (nodeInfo[n].first == nodeInfo[n].second) {
                vector <int> v;
                int i;
                do {
                    i = s.top();
                    s.pop();
                    v.push_back(i + 1);
                    inStack[i] = false;
                } while ( i != n );
                cout << "Components \n";
                for (int i = 0; i < v.size(); i++) cout << v[i] << "  ";
                cout << "\n";
            }
        }
};

int main() {
    Scc c;
    c.start();
    return 0;
}
