#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
const int SZ = 100;
class TestHolzer {
    public:
        int adjMatrix[SZ][SZ];
        int N;
        int inD[SZ], outD[SZ];
        void start() {
            memset(adjMatrix, 0, sizeof(int) * SZ * SZ);
            memset(inD, 0, sizeof(int) * SZ);
            memset(outD, 0, sizeof(int) * SZ);
            int a, b;
            cin >> N;
            for (int i = 0 ; i < N; i++) {
                cin >> a >> b;
                adjMatrix[a][b]++;
                inD[b]++;
                outD[a]++;
            }
            int start = -1, end = -1;
            for (int i = 0; i < SZ; i++) {
                if (inD[i] < outD[i]) start = i;
                if (inD[i] > outD[i]) end = i;
            }
            for (int i = 0 ; i < SZ && start == -1; i++) {
                if (hasOutgoingEdges(i)) start = i;
            }
            cout << "End= " << end << "Start =" << start << "\n";
            if ( end != -1 && adjMatrix[end][start] == 0) adjMatrix[end][start]++;
            vector <int> res;
            doHolzersShit(start, 0, res);
            if (end == -1) res.push_back(start);
            for (int i = 0; i < res.size(); i++) {
                cout << "Node = " << res[i] << " ";
            }
        }
        void printMatrix(int r = SZ) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < r; j++) {
                    cout << adjMatrix[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }

        bool hasOutgoingEdges(int n) {
            return getNextNode(n) != -1;
        }

        int getOutDegree(int n) {
            int res = 0;
            for (int i = 0; i < SZ; i++) {
                res += adjMatrix[n][i];
            }
            return res;
        }
        int getNextNode(int n) {
            for (int i = 0; i < SZ; i++) {
                if (adjMatrix[n][i] > 0) return i;
            }
            return -1;
        }
        void doHolzersShit(int node, size_t pos, vector<int>& out) {
            printMatrix(10);
            cout << "DOing for node = " << node << " Pos =" << pos << "\n";
            int nextStartNode = -1;
            int next = getNextNode(node);
            vector<int> v;
            size_t shift = 0;
            int curr = node;
            if (next !=  -1) {
                do {
                    next = getNextNode(curr);
                    cout << "Curr =" << curr << "Next =" << next << "\n";
                    if ((nextStartNode == -1) && (getOutDegree(curr) > 1)){
                        nextStartNode = curr;
                    }
                    adjMatrix[curr][next]--;
                    v.push_back(curr);
                    curr = next;
                    if (nextStartNode == -1) shift++;
                } while (next != node);
                if (nextStartNode != -1) {
                    doHolzersShit(nextStartNode, shift, v);
                }
                out.insert(out.begin() + pos, v.begin(), v.end());
            }    
        }

};

TestHolzer th;
int main(int argc, char **argv) {
    th.start();
    return 0;
}
        /*
        string convertIntToString(vector<int>& v) {
            string res;
            REP (i, v.size()) {
                cout << "STRING = " << getString(v[i]) << "\n";
                if (res.empty()) {
                    res = getString(v[i]);
                } else {
                    res += getString(v[i])[1];
                }
            }
            return res;
        }
        vector<int> doHolzersShit(int node) {
            cout << "DOing for node = " << node << "\n";
            int nextStartNode = -1;
            int next = getNextNode(node);
            vector<int> v;
            size_t shift = 0;
            int curr = node;
            if (next !=  -1) {
                do {
                    next = getNextNode(curr);
                    cout << "Curr =" << curr << "Next =" << next << "\n";
                    if ((nextStartNode == -1) && (getOutDegree(curr) > 1)){
                        nextStartNode = curr;
                    }
                    adjMatrix[curr][next]--;
                    v.push_back(curr);
                    curr = next;
                    if (nextStartNode == -1) shift++;
                } while (curr != node && curr != -1);
                bool isLoop = false;
                if (curr != -1) {
                    v.push_back(node);
                    isLoop = true; 
                }
                REP (i, v.size()) cout << " V In this iter " << i << " " <<  v[i] << "\n";
                cout << "Next start node " << nextStartNode << "\n";
                if (nextStartNode != -1) {
                    vector<int> t = doHolzersShit(nextStartNode);
                    if (isLoop) {
                        v.insert(v.end(), t.begin() + 1, t.end());
                    } else {

                        v.insert(v.begin() + shift -1, t.begin() + 1, t.end());
                    }
                }
                REP (i, v.size()) cout << "FINAL out V" << i << " " <<  v[i] << "\n";
                cout << "\n";

            } else {
                v.push_back(node);
            }

            return v;    
        }
        bool hasOutgoingEdges(int n) {
            return getNextNode(n) != -1;
        }

        int getOutDegree(int n) {
            int res = 0;
            for (int i = 0; i < SZ; i++) {
                res += adjMatrix[n][i];
            }
            return res;
        }
        int getNextNode(int n) {
            for (int i = 0; i < SZ; i++) {
                if (adjMatrix[n][i] > 0) return i;
            }
            return -1;
        }
        */
