#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>


using namespace std;

const int SZ = 10000;
typedef vector <int> VI;
class Sorter {
    public:
        vector <int> store;
        void populateStore() {
            for (int i = 0 ; i < SZ; i++) {
                store.push_back(rand());
            }
        }

        void moveMaxToEnd(VI& s, int end) {
            for (int  i = 0 ; i < end -1; i++) {
                if (s[i] > s[i+1]) swap(s[i], s[i+1]);
            }
        }
        void bubbleSort() {
            for (int i = store.size(); i > 1; i--) {
                moveMaxToEnd(store, i);
            }
        }

        void mergeSort() {
            mergeSort(0, store.size());
        }

        void copyInRange(int start, int end, VI& t, VI& s) {
            for (int i = start; i < end; i++) {
                t.push_back(s[i]);
            }
        }
        void mergeSort(int start, int end) {
            if (end - start == 1) return;
            int mid = (start + end)/2;
            mergeSort(start, mid);
            mergeSort(mid, end);
            vector<int> temp;
            int p1 = start;
            int p2 = mid;
            while (p1 < mid && p2 < end) {
                if (store[p1] <= store[p2]) {
                    temp.push_back(store[p1++]);
                } else {
                    temp.push_back(store[p2++]);
                }
            }
            if (p1 == mid) {
                copyInRange(p2, end, temp, store);
            }
            if (p2 == end) {
                copyInRange(p1, mid, temp, store);
            }
            for (int i = start; i < end; i++) {
                store[i] = temp[i - start];
            }
        }

        void qSort() {
            qSort(0, store.size());
        }
        void qSort(int start, int end) {
            if (end - start == 1) return;
            int mid = (start + end)/2;
            int hp = start;
            int lp = end -1;
            while (hp <= lp ) {
                while(store[hp] <= store[mid] && hp <= lp) hp++;
                while(store[lp] > store[mid] && hp <= lp) lp--;

            }
        }
        bool isSorted() {
            for (int i = 0; i < store.size() -1; i++) {
                if (store[i] > store[i+1]) return false;
            }
            return true;
        }
};

int main() {
    Sorter sorter;
    sorter.populateStore();
    sorter.mergeSort();
    cout << "Sorted = " << sorter.isSorted() << "\n";
    return 0;
}
