#include <bits/stdc++.h>


using namespace std;
using VI = vector<int>;
using LL = long long;


const bool dbg = !true;

struct A {
    vector<int> stk;
    int N;
    int res;
    int lastPopped;

    void start() {
        res = 0;
        lastPopped = 0;
        cin >> N;
        for (int i = 0; i < 2 * N; i++) {
            string s; cin >> s;
            if (s == "add") {
                int t; cin >> t;
                add(t);
            } else {
                pop();
            }
        }

        cout << res << "\n";
    }

    void add(int t) {
        if (dbg) cout << "Adding " << t <<  " to the stack\n";
        stk.push_back(t);
    }

    void pop() {
        lastPopped++;
        if (stk.empty()) { 
            if (dbg) cout << "Stack is empty, assume it is sorted\n";
            return;
        }
        int t = *stk.rbegin();
        if (t == lastPopped) {
            if (dbg) {
                cout << " element on stack matches the one to pop no need to shuffle\n";
            }
            stk.pop_back();
        } else {
            res++;
            stk.clear();
            if (dbg) {
                cout << " element on top is not the one that needs to be popped, incrementing res to " << res << " and clearing vector\n";
            }
        }
        
    }

};

A a;
int main() {
    a.start();
    return 0;
}
