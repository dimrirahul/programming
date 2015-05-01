#include<bits/stdc++.h>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FORU(I,A,B) for(unsigned int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define REPU(I,N)   FORU(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

typedef pair <int, int> PI;
typedef vector <int> VI;
typedef vector <string> VS;

typedef long long LL;
const int SZ = 509;
const bool dbg = false;
class C {
    public:
        int matrix[SZ][SZ];
        PI start, end, dim;
        void readPi(PI &pi) {
            cin >> pi.first >> pi.second;
        }
        bool inRange(int v, int e) {
            return v >= 0 && v < e;
        }

        bool isValid(PI &curr) {
            return inRange(curr.first, dim.first) && inRange(curr.second, dim.second);
        }

        int getVal(PI pt) {
            return matrix[pt.first][pt.second];
        }

        void addPtVal(PI pt, int val) {
            matrix[pt.first][pt.second] += val;
        }

        void reducePi(PI &pi) {
            pi.first--;
            pi.second--;
        }

        string printPi(PI &pi) {
            stringstream ss;
            ss << "[" << pi.first << "," << pi.second << "]";
            return ss.str();
        }

        void printMatrix() {
            for (int i = 0; i < dim.first; i++) {
                for (int j = 0; j < dim.second; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << "\n";
            }
        }

        bool canStepOnTile(PI& curr) {
            if (curr == end) return true;
            else return getVal(curr) > 1;
        }

        void addNeighbors(PI& curr, stack<PI> &s ) {
            int arr1[] = {-1, 1, 0, 0};
            int arr2[] = {0, 0, -1, 1};
            for (int i = 0; i < 4; i++) {
                PI neigh = make_pair(curr.first + arr1[i] , curr.second + arr2[i]);
                if (isValid(neigh) && canStepOnTile(neigh)) {
                    s.push(neigh);
                    if (dbg) {
                        cout << "Parent = " << printPi(curr) << " Added neigh " << printPi(neigh);
                    }
                }
            }
        }
        bool isPossible(PI curr) {
            bool res = false;
            stack<PI> s;
            s.push(curr);
            while (!s.empty() && !res) {
                PI t = s.top();
                if (dbg) cout << "Popped=" << printPi(t) << "\n";
                res = (t == end && (getVal(t) == 1 || getVal(t) == 0) && getVal(start) == 0);
                s.pop();
                if (getVal(t) == 0) continue;
                addPtVal(t, -1);
                addNeighbors(t, s);
            }
            return res;
        }
        void startProcessing() {
            readPi(dim);
            for (int i = 0; i < dim.first; i++) {
                string s;
                cin >> s;
                for (int j = 0; j < s.size(); j++) {
                    if (s[j] == 'X') matrix[i][j] = 1;
                    else matrix[i][j] = 2;
                }
            }
            readPi(start);
            readPi(end);
            reducePi(start);
            reducePi(end);
            if (isPossible(start)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }    
};

C t;

int main(int argc, char **argv) {
    t.startProcessing();
    return 0;
}
