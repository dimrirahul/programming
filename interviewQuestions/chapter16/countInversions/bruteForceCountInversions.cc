#include <vector>
#include <iostream>

using namespace std;

vector<int> inputV;

void solve() {
    int res = 0;
    for (int i = 0; i < inputV.size(); i++) {
        for (int j = i+1; j < inputV.size(); j++) {
            if (inputV[i] > inputV[j]) res++;
        }
    }
    cout << res << "\n";
}
void start() {
    int numTests, countInput, input;
    cin >> numTests;
    for (int i = 0; i < numTests; i++) {
        inputV.clear();
        cin >> countInput;
        for (int j = 0; j < countInput; j++) {
            cin >> input;
            inputV.push_back(input);
        }
        solve();
        //printTree(root);
    }
}

int main(int argc, char **argv) {
    start();
    return 0;
}


