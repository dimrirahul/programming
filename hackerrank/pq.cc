#include <queue>
#include <iostream>

using namespace std;
int main() {
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < 10 ; i++)
        pq.push(i);

    for (int i = 0;i < 10; i++) {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}


