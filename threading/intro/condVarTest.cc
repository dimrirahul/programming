#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <queue>


using namespace std;

queue <int> dq;
mutex dqMutex;
condition_variable condVarDqMutex;

const int NUM_ITEMS = 10;
void producer() {
    for (int i = 0; i < NUM_ITEMS; i++) {
        unique_lock<mutex> ulock(dqMutex);
        condVarDqMutex.wait(ulock, [] { return dq.size() == 0; });
        dq.push(i);
        this_thread::sleep_for(std::chrono::seconds(1));
        ulock.unlock();
        condVarDqMutex.notify_all();
    }
}

void consumer() {
    int countItems = 0;
    while (countItems < NUM_ITEMS) {
        unique_lock<mutex> ulock(dqMutex);
        condVarDqMutex.wait(ulock, [] { return dq.size() > 0; });
        int x = dq.front();
        dq.pop();
        cout << " Element popped = " << x << "\n";
        countItems++;
        ulock.unlock();
        condVarDqMutex.notify_all();
    }
}


int main(int argc, char **argv) {
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}
