#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <memory>

using namespace std;

using VI = vector<int>;

struct AbstractWindow {
    void initializeWindow(VI* vi, int startPos) = 0;
    void moveWindowLeft() = 0;
    void moveWindowRight() = 0;
    int getMaxDiff() = 0;
    //void printWindow() = 0;
};

struct BruteForce : public AbstractWindow {
    BruteForce() : vi(NULL), startPos(0) {}

    void initializeWindow(VI* viInp, int startPosInp) {
        vi = viInp;
        startPos = startPosInp;
    }

    void moveWindowLeft() {
        startPos--;
    }

    void moveWindowRight() {
        startPos++;
    }

    int getMaxDiff() {
        int m1 = -1;
        int m2 = -1;
        for (int i = startPos; i < startPos + WINDOW_SIZE; i++) {
            if ( i < 0 || i >= vi->size()) continue;
            if (m1 < 0) m1 = *vi[i];
            else m1 = min(*vi[i], m1);
            if (m2 < 0) m2 = *vi[i];
            else m2 = max(*vi[i], m2);
        }
        if (m1 != -1 && m2 != -1) return m2 - m1;
        return -1;
    }

    int startPos;
    VI* vi;

};

struct ListBased : public AbstractWindow {
    ListBased() : vi(NULL), startPos(0), minValue(-1), maxValue(-1) {}

    void initializeWindow(VI* viInp, int startPosInp) {
        vi = viInp;
        startPos = startPosInp;
    }

    void moveWindowLeft() {
    }

    void moveWindowRight() {
    }

    int startPos;
    VI* vi;
    int minValue;
    int maxValue;
};

struct TreeBased : public AbstractWindow {
};

const int MAX_SIZE = 100;
const int WINDOW_SIZE = 10;
const int MAX_MOVES = 50;

VI populateInput(int size) {
    VI res;
    for (int i = 0; i < size; i++) res.push_back(i);
    random_shuffle(res.begin(), res.end());
    return res;
}

VI getMoves(int size) {
    VI res;
    for (int i = 0; i < size; i++) res.push_back(i % 2);
    random_shuffle(res.begin(), res.end());
    return res;
}

int main() {
    VI input = populateInput(MAX_SIZE);
    VI moves = getMoves(MAX_MOVES);
    E
}
