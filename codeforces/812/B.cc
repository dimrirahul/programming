#include <iostream>
#include <vector>
#include <array>

using namespace std;

const int MX_COLS = 120;
const int MX_ROWS = 100;
const bool dbg = true;
const int INF = 9999999;

using Matrix = array<array<bool, MX_COLS>, MX_ROWS>;

struct B {
    Matrix matrix;
    int rows, cols;
    array<int, MX_ROWS> clb, cle, crb, cre, lm, rm; //clb = countLeftBegin, cle= countLeftEnd
    int result;

    void init() {
        for (auto &it : matrix) it.fill(false);
        clb.fill(INF);
        cle.fill(INF);
        crb.fill(INF);
        cre.fill(INF);
        clb[0] = 0;
        result = INF;
        lm.fill(MX_COLS);
        rm.fill(0);
    }

    void readInput() {
        cin >> rows >> cols;
        vector<string> strVector;
        for (int i = 0; i < rows; i++) {
            string str;
            cin >> str;
            strVector.push_back(str);
        }
        int i = 0;
        for (auto s = strVector.rbegin(); s != strVector.rend(); s++, i++) {
            for (int j = 0; j < s->size(); j++) {
                if ((*s)[j] == '1') {
                    matrix[i][j] = true;
                    lm[i] = min(lm[i], j);
                    rm[i] = max(rm[i], j);
                }
            }
        }
    }

    void optimize() {
        for (int i = 0; i < rows -1 ; i++) {
            int costToGoRighmostFromLeft = clb[i] + rm[i];
            int costToGoRightmostAndGoToLeftEnd = costToGoRighmostFromLeft + rm[i];
            int costToGoRightmostAndGoToRightEnd = clb[i] + cols;

            int costToGoLeftmostFromRight = crb[i] + cols - lm[i];
            int costToGoLeftmostFromRightToRightEnd = costToGoLeftmostFromRight + (cols - lm[i]);
            int costToGoLeftmostFromRightToLeftEnd = crb[i] + cols;
            clb[i+1] = min(costToGoRightmostAndGoToLeftEnd, costToGoLeftmostFromRightToLeftEnd) + 1;
            crb[i+1] = min(costToGoRightmostAndGoToRightEnd, costToGoLeftmostFromRightToRightEnd) + 1;
        }
    }

    void generateResult() {
        result = min(
                clb[rows - 2] + rm[rows -1],
                crb[rows - 2] + cols - lm[rows -1]
                );

    }

    void printDebug() {
        cout << "Rows=" << rows << " Cols=" << cols << "\n";
        for (int i = 0; i < rows; i++) {
            cout << "lm[" << i << "]=" << lm[i] << " rm[" << i << "]=" << rm[i] << " clb[" << i << "]=" << clb[i] << " crb[" << i << "]=" << crb[i] << "\n";
        }
    }

    void start() {
        init();
        readInput();
        if (dbg) printDebug();
        optimize();
        generateResult();
        cout << result << "\n";
    }
};

B b;
int main(int argc, char **argv) {
    b.start();
    return 0;
}
