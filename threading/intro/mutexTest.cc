#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <mutex>
#include <thread>

using namespace std;

const int NUM_THREADS = 5;


mutex cout_mutex;
void printLine(int tid, int i) {
    lock_guard<mutex> gl(cout_mutex);
    if ( i%2 == 0 ) throw logic_error(" Even ");
    cout << "Tid=" << tid << " val =" << i << "\n";
}
void printNums(int tid) {
    for (int i = 0; i < 20; i++) {
        try {
            printLine(tid, i);
        } catch (...) {
            //cout << "Catching exception\n";
        }
    }
}

int main(int argc, char **argv) {
    thread tArr[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) tArr[i] = thread(printNums, i);
    for (int i = 0; i < NUM_THREADS; i++) tArr[i].join();
    return 0;
}
