#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> res(n+1);
    vector<pair<int, int>> input;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        input.push_back(make_pair(t, i+1));
        sort(begin(input), end(input));
        reverse(begin(input), end(input));
    }
    for (int i = 0; i < input.size(); i++) {
        if ( i > 0 && input[i-1].first == input[i].first) {
            int r = res[input[i-1].second];
            res[input[i].second] = r;
        } else {
            res[input[i].second] = i+1;
        }
    }
    for (int i =1 ; i < res.size(); i++) cout << res[i] << " ";
    cout << "\n";
    return 0;
}
