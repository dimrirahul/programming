#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<int, int> PI;
class CLASS {
    public:
        vector<PI> info;
        int N;
        int K;

        void start() {
            scanf("%d %d\n", &N, &K);
            for (int i = 0 ; i < N; i++) {
                int a;
                scanf("%d ", &a);
                info.push_back(make_pair(a, i+1));
            }
            sort(info.begin(), info.end());
            vector<int> res;
            for (int i = 0; i < info.size() && K > 0; i++) {
                if (K - info[i].first >= 0) {
                    K -= info[i].first;
                    res.push_back(info[i].second);
                } else {
                    break;
                }
            }
            cout << res.size() << "\n";
            for (int i = 0 ; i < res.size(); i++) cout << res[i] << " ";
            cout << "\n";
        }
};

CLASS kt;
int main(int argc, char **argv) {
    kt.start();
    return 0;
}
