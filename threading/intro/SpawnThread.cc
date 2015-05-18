#include <iostream>
#include <thread>

using namespace std;


void func1() {
    cout << "Hello from thread\n";
}

int main(int argc, char **argv) {
    for (int i = 0; i < 5; i++) {
        thread t(func1);
        t.detach();
        //if (t.joinable())

        t.join();
    }
    return 0;
}
