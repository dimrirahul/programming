#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;
int MX = 1000;
const bool dbg = true;
struct C {
    vector<int> next;
    vector<bool> visited;
    int startFrom(int idx) {
        pair<bool, int> loopCheckOutput = checkForLoop(idx);
        if (loopCheckOutput.first) return loopCheckOutput.second;
        else return MX;
    }

    pair<bool, int> checkForLoop(int idx) {
        pair<bool, int> res = make_pair(false, 0);
        stack<int> stk;
        stk.push(idx);
        bool hasLoop = false;
        int p = -1;
        while (!stk.empty()) {
            p = stk.top();
            stk.pop();
            if (visited[p]) {
                hasLoop = true;
                if (dbg) {
                    cout << "Starting at idx=" << idx << " there is a way to get to a cycle\n";
                }
                break;
            }
            visited[p] = true;
            int neighbor = next[p];
            if (neighbor == p) {
                if (dbg) cout << "Stopping at index=" <<p << " cause it is in love with itself\n";
                break;
            }
            stk.push(neighbor);
        }
        if (!hasLoop) {
            if (dbg) cout << "No loop found from node=" << idx << "returning early\n";
            return res;
        }

        int sNode = p;
        int len = 1;
        int nNode = next[sNode];

        if (dbg) {
            cout << "Starting index for circular check=" << sNode << " nextNode =" << nNode << "\n";
        }
        while (nNode != sNode) {
            len++;
            nNode = next[nNode];
        }


        if (dbg) {
            cout << "Length of cycle=" << len << "\n";
        }
        if (len %2 != 0)
            return res;
        else
            return make_pair(true, len/2);

    }


    void start() {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int t; cin >> t;
            t--;
            next.push_back(t);
            visited.push_back(false);
        }
        int res = MX;
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                res = min(res, startFrom(i));
            else if (dbg) {
                cout << "Skipping node=" << i << " cause it has been part of some previous dfs" << "\n";
            }
        }
        if (res == MX) cout << -1;
        else cout << res;
        cout << "\n";
    }
    int n;
};

int main() {
    C c;
    c.start();
    return 0;
}
