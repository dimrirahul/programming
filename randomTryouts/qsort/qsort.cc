#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>


using namespace std;

void printVector(vector<int>& v, const char *ptr);
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

        int rankFinder(int start, int end, vector<int>& v, int rank) {
            if (end - start == 1) return start;
            if (rank > (end - start)) return -1;
            int less = start, more = end - 1, pivot = (start +  end ) >> 1;
            while (less < more) {
                while (v[less] <= v[pivot] && less < more) less++;
                while (v[more] >= v[pivot] && less < more) more--;
                if (v[less] > v[more]) swap(v[less], v[more]);
            }
            if ((less > pivot && v[pivot] > v[less]) || (less < pivot && v[less] > v[pivot])) swap(v[pivot], v[less]);
            if (less == rank) return less;
            else if (less > rank) return rankFinder(start, less, v, rank);
            else return rankFinder(less, end, v, rank - less -1);
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

        bool hasCorrectRank(vector<int> v, int expected, int actual) {
            sort(v.begin(), v.end());
            printVector(v, " Sorted vector");
            if (v[expected] != actual) {
                printf("Rekt expected value=%d actual value=%d\n", v[expected], actual);
                return false;
            } else {
                printf("Okay");
                return true;
            }
        
        }
};

Qsort s;

void printVector(vector<int>& v, const char *ptr) {
    printf("%s\n", ptr);
    for (int i = 0 ; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}
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
    vector<int> v1 = v;
    int p = s.rankFinder(0, v.size(), v, 13);
    printVector(v, "Ordered vector");
    if (s.hasCorrectRank(v1, 13, v[p])) {
        printf("Okay\n");
    } else {
        printf("Rekt\n");
    }
}


