#include <iostream>
#include <map>
#include <vector>
#include <array>

using namespace std;

const int ALPHABET_SPACE = 26 * 2;
const int NUM_ENTRIES = ((int)1e5) + 10;

int store[NUM_ENTRIES][ALPHABET_SPACE];

int getKey(char ch) {
    int res = ch - 'A';
    if (ch >= 'A' && ch <= 'Z') return res;
    res = ch - 'a';
    return res + 26;
}

void getDelta(int startIdx, int endIdx, int* res) {
    for (int i = 0; i < ALPHABET_SPACE; i++) {
        res[i] = store[endIdx][i];
        if (startIdx > 0) {
            res[i] -= store[startIdx-1][i];
        }
    }
}

bool bitwiseCompare(int* ptr1, int* ptr2) {
    for (int i = 0; i < ALPHABET_SPACE; i++) {
        if ((ptr1[i] > 0 && ptr2[i] == 0) ||
                (ptr1[i] == 0 && ptr2[i] != 0)) return false;
    }
    return true;
}


int doBinarySearch(int start, int numElements) {
    int epBeg = start;
    int epEnd = numElements;
    int res = NUM_ENTRIES;
    while (epBeg < epEnd) {
        int mid = (epBeg + epEnd)/2;
        int delta[ALPHABET_SPACE];
        getDelta(start, mid, delta);
        if (bitwiseCompare(delta, store[numElements-1])) {
            int d = mid - start + 1;
            res = min(res, d);
            epEnd = mid;
        } else {
            epBeg = mid+1;
        }
    }
    return res;
}

int main() {
    for (int i = 0; i < NUM_ENTRIES; i++) {
        for (int j = 0; j < ALPHABET_SPACE; j++) {
            store[i][j] = 0;
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (i > 0) for (int j = 0; j < ALPHABET_SPACE; j++) store[i][j] = store[i-1][j];
        char ch;
        cin >> ch;
        store[i][getKey(ch)]++;
    }

    int res = n;
    for (int i = 0; i < n; i++) {
        res = min(res, doBinarySearch(i, n));
    }
    cout << res << "\n";
    return 0;

}
