
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

typedef vector<string> VS;

class Cube {
    public:
        int fv;
        Cube() {
            fv = 1;
        }

        Cube (int fv) {
            this->fv = fv;
        }

        void rollLeft() {
            if (fv == 1) fv = 4;
            else if (fv == 2) fv = 1;
            else if (fv == 3) fv = 2;
            else if (fv == 4) fv = 3;
            else if (fv == 5) fv = 2;
            else if (fv == 6) fv = 4;
        }

        void rollRight() {
            if (fv == 1) fv = 2;
            else if (fv == 2) fv = 3;
            else if (fv == 3) fv = 4;
            else if (fv == 4) fv = 1;
            else if (fv == 5) fv = 4;
            else if (fv == 6) fv = 2;
        }

        void rollUp() {
            if (fv == 1 || fv == 2 || fv == 3 || fv == 4) fv = 5;
            else if (fv == 5 || fv == 6) fv = 1;
        }

        void rollDown() {
            if (fv == 1 || fv == 2 || fv == 3 || fv == 4) fv = 6;
            else if (fv == 5 || fv == 6) fv = 3;
        }
};
class CubeNets {
    public:

        void rollCube(VS& matrix, int x, int y, int  fv) {
            Cube cube(fv);
            matrix[x][y] = cube.fv + '0';
            int loop[] = {-1, 1};
            for (int i = 0; i < 2; i++) {
                int newX = x + loop[i];
                if (newX < matrix.size() && newX >= 0 && matrix[newX][y] == '#') {
                    Cube c2(cube.fv);
                    if (i == 0) {
                        c2.rollUp();
                    } else {
                        c2.rollDown();
                    }
                    rollCube(matrix, newX, y, c2.fv);
                }

                int newY = y + loop[i];
                if (newY < matrix[x].size() && newY >= 0 && matrix[x][newY] == '#') {
                    Cube c2(cube.fv);
                    if (i == 0) {
                        c2.rollLeft();
                    } else {
                        c2.rollRight();
                    }
                    rollCube(matrix, x, newY, c2.fv);
                }
            }
        }

        bool checkMatrix(VS& matrix) {
            bool check[] = {false, false, false, false, false, false};
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0;  j < matrix[i].size(); j++) {
                    if (matrix[i][j] == '#') {
                        return false;
                    } else if (matrix[i][j] >= '1' && matrix[i][j] <= '6') {
                        check[matrix[i][j]-'1'] = true;
                    }
                }
            }

            REP(i,6) {
                if (check[i] == false) return false;
            }
            return true;
        }

        void printMatrix(VS& matrix) {
            REP(i, matrix.size()) {
                REP(j, matrix[i].size()) {
                    cout << matrix[i][j] << "  ";
                }
                cout << "\n";
            }

        }

        string isCubeNet(vector <string> matrix)
        {
            const string no = "NO"; const string yes = "YES";
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    if (matrix[i][j] == '#') {
                        rollCube(matrix, i, j, 1);
                        printMatrix(matrix);
                        return checkMatrix(matrix) ? yes: no;
                    }
                }
            }
            return no; 
        }
};

