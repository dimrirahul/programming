#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;
const int SZ = 17;
class BruteForce {
    public:
        vector <int> pv;
        int matrix[SZ][SZ];

        void setPv(vector <int> p) {
            pv.insert(pv.end(), p.begin(), p.end());
        }

        void createAdjMatrix() {
            for (int i = 0; i < SZ; i++) {
                for (int j = 0; j < SZ; j++) {
                    matrix[i][j] = 0;
                }
            }

            for (int i = 0; i < pv.size(); i++) {
                matrix[i+1][pv[i]] = matrix[pv[i]][i+1] = 1;
            }
        }

        pair <int, int> childrenUnderMe(int nodeId, int mask) {
            int r = 0, g = 0;
            for (int i = nodeId+1; i < SZ; i++) {
                if (matrix[nodeId][i] == 1) {
                    if (mask & (1 << (SZ - 1 -i))) {
                        r++;
                    } else {
                        g++;
                    }
                    pair <int , int> res = childrenUnderMe(i, mask);
                    g += res.first;
                    r += res.second;
                } 
            }
            return make_pair(g, r);
        }
        void assignAndCalcCost() {
            int minC = 10000000; int minV = 0;
            for (int j = 0; j < (1 << SZ); j++) {
                int cost = 0;

                for (int i = 0; i < SZ; i++) {
                    pair <int, int> p = childrenUnderMe(i, j);
                    if (j & (1 << (SZ - 1 - i))) {
                        cost += (p.second + 1);
                    } else {
                        cost += (p.first + 1);
                    }
                }

                if (cost <= 26) {
                    cout << "cost == " << cost << "J=" << j << "\n";
                    drawTree(j); 
                }
                if (cost < minC) {
                    minC = cost;
                    minV = j;

                }
            }
            cout << "cost == " << minC << "J=" << minV << "\n";

        }

        void drawTree(int mask) {
            for (int i = 0; i < SZ; i++) {
                int c = 0;
                if (mask & (1 << (SZ- 1-i))) {
                   c = 1;
                }
                printf("Node = %d, color=%s\n", i, (c == 0 ? "Green" : "Red"));
            }
            cout << "============";
        }

};

BruteForce bf;
int main(int argc, char **argv) {
    vector<int> p;
    p.push_back(0);
    p.push_back(0);
    p.push_back(1);
    p.push_back(0);
    p.push_back(4);
    p.push_back(3);
    p.push_back(5);
    p.push_back(2); p.push_back( 0); p.push_back( 7); p.push_back( 9);p.push_back( 2);p.push_back( 4);p.push_back( 5);p.push_back( 3);p.push_back( 1);
    bf.setPv(p);
    bf.createAdjMatrix();
    bf.assignAndCalcCost();
    return 0;
}
