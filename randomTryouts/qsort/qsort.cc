#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>


using namespace std;

class Qsort {
    public:
        void quicksort(vector<int>&v, int start, int end) {
            if (start >= end || (end - start == 1)) return;
            int less = start, more = end -1, pivot;
            pivot = (start + end) >> 1;
            while (less < more) {
                while (v[less] <= v[pivot] && less < more) less++;
                while(v[more] >= v[pivot] && less < more) more--;
                if (v[less] > v[more]) swap(v[less], v[more]);
            }
            if ((less > pivot && v[pivot] > v[less]) || (less < pivot && v[less] > v[pivot])) swap(v[pivot], v[less]);
            quicksort(v, start, less );
            quicksort(v, less, end);
        }

        bool isCorrect(vector<int> &sortedByMe) {
            vector<int> q = sortedByMe;
            sort(q.begin(), q.end());
            bool res = true;
            for (int i = 0; i < q.size(); i++) {
                printf("Index=%d, correct=%d, myValue=%d\n", i, q[i], sortedByMe[i]);
                if (q[i] != sortedByMe[i]) res = false;
            }
            return res;
        }
};

Qsort s;

vector<int> test1() {
    vector<int> res;
    int n, p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p;
        res.push_back(p);
    }
    return res;
}
int main(int argc, char **argv) {
    vector<int> v = test1();
    s.quicksort(v, 0, v.size());
    if (s.isCorrect(v)) {
        printf("Okay\n");
    } else {
        printf("Rekt\n");
    }
}


