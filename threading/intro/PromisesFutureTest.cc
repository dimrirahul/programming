#include <iostream>
#include <mutex>
#include <vector>
#include <algorithm>
#include <thread>
#include <future>


using namespace std;

int thread1(promise<int>& p, int n1) {
    std::this_thread::sleep_for(std::chrono::seconds(4));
    p.set_value(n1);
    return 5;
}

int thread2(future<int> &t1F, future<int> &t2F) {
    int t2Res = t2F.get();
    int t1Res = t1F.get();
    return t2Res * t1Res;
}

int thread3() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 6;
}

int main(int argc, char **Argv) {
    promise<int> p;
    future<int> pf = p.get_future();
    future<int> f1 = async(launch::async, thread1, ref(p), 2);
    future<int> f3 = async(launch::async, thread3);
    future<int> f2 = async(launch::async, thread2, ref(pf), ref(f3));
    int v = f2.get();
    cout << "value = "  << v << "\n";

}
