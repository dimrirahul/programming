#include <iostream>
#include <thread>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int TOT_THREADS = 10;
const int SZ = 1000;
vector<int> numbers;
void populateNumbers() {
    for (int i = 0; i < SZ; i++) {
        numbers.push_back(rand());
    }
}
void print() {
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << "\n";
    }
    cout << "\n";
}

bool isSorted() {
    for (int i = 0; i < numbers.size() -1; i++) {
        if (numbers[i] > numbers[i+1]) return false;
    }
    return true;
}
void sortInplace(int id, int totThreads) {
    //cout << "Sorting string for chunk = " << id + 1 << "\n";
    int chunkSize = SZ / totThreads;
    int start = id * chunkSize;
    //int end = min(start + chunkSize,(int) numbers.size());
    int end = (id+1) * chunkSize;
    //cout << "Sorting from start: " <<  start << " to end: " << end << "\n";
    sort(numbers.begin() + start, numbers.begin() + end);
    bool sorted = true;
    for (int i = start; i < end -1; i++) {
        if (numbers[i] > numbers[i+1]) sorted = false;
    }
    //cout << " Chunk sorting of " << start << " to end " << end << " is =" << sorted << "\n";
    //cout << " Printing from thread\n";
    //print();

}
typedef pair <int, int> PI;
class Sorter {
    public:
        bool operator()(PI p1, PI p2) {
            if (p1.first != p2.first) return p1.first > p2.first;
            return p1.second > p2.second;
        }
};

void merge() {
    vector<int> out;
    priority_queue<PI, vector <PI> , Sorter> pq;
    int chunkSize = SZ/ TOT_THREADS;
    for (int i = 0; i < TOT_THREADS; i++) {
        pq.push(make_pair(numbers[chunkSize * i], i*chunkSize));
    }
    while (!pq.empty()) {
        pair <int, int> e = pq.top();
        pq.pop();
        out.push_back(e.first);
        int nextPos = e.second + 1;
        if (nextPos % chunkSize != 0) {
            pq.push(make_pair(numbers[nextPos], nextPos));
        }
    }
    bool outSorted = true;
    for (int i = 0; i < out.size()-1; i++) {
        if (out[i] > out[i+1]) outSorted = false;
    }
    cout << "Is out sorted = " << outSorted << " \n";
    numbers = out;
    for (int i = 0; i < out.size(); i++) cout << out[i] << "\n";
}

int main() {
    populateNumbers();
    thread tArr[TOT_THREADS];
    for (int i = 0;i < TOT_THREADS; i++) {
        tArr[i] = thread(sortInplace, i, TOT_THREADS);
    }
    for (int i = 0; i < TOT_THREADS; i++) {
        tArr[i].join();
    }
    //there is a merge step left.
    merge();
    //print();
    cout << " is Sorted = " << isSorted() << "\n";
    return 0;
}
