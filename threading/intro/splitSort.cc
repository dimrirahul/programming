#include <iostream>
#include <thread>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <mutex>

using namespace std;

const int SZ = 100;
mutex mu;
class ThreadedSorting {
    public:
        ThreadedSorting() {
            cout << "Creating an instance of functor\n";
        }
        vector<int> numbers;
        void populateNumbers() {
            for (int i = 0; i < SZ; i++) {
                numbers.push_back(rand());
            }
        }

        void operator()(int id, int totThreads) {
            mu.lock();
            cout << "Sorting string for chunk = " << id + 1 << "\n";
            int chunkSize = SZ / totThreads;
            int start = id * chunkSize;
            //int end = min(start + chunkSize,(int) numbers.size());
            int end = (id+1) * chunkSize;
            cout << "Sorting from start: " <<  start << " to end: " << end << "\n";
            sort(numbers.begin() + start, numbers.begin() + end);
            bool sorted = true;
            for (int i = start; i < end -1; i++) {
                if (numbers[i] > numbers[i+1]) sorted = false;
            }
            cout << " Chunk sorting of " << start << " to end " << end << " is =" << sorted << "\n";
            cout << " Printing from thread\n";
            print();
            mu.unlock();
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
};

ThreadedSorting ts;
const int TOT_THREADS = 1;
int main() {
    mu.lock();
    ts.populateNumbers();
    mu.unlock();
    thread tArr[TOT_THREADS];
    for (int i = 0;i < TOT_THREADS; i++) {
        tArr[i] = thread(ref(ts), i, TOT_THREADS);
    }
    for (int i = 0; i < TOT_THREADS; i++) {
        tArr[i].join();
    }
    mu.lock();
    ts.print();
    mu.unlock();
    cout << " is Sorted = " << ts.isSorted() << "\n";
    return 0;

}
