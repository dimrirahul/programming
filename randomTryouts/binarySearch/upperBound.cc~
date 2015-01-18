#include <algorithm>
#include <cstdio>
#include <vector>


using namespace std;

class UpperBound {
    public:
        vector<int> storev;

        void start() {
            int t1, t2;
            int value;
            scanf("%d\n", &t1);
            for (int i = 0; i < t1; i++) {
                scanf("%d ", &t2);
                storev.push_back(t2);
            }
            scanf("%d\n", &value);
            sort(storev.begin(), storev.end());

            for (int i = 0; i < storev.size(); i++) {
                printf("index =%d value = %d\n", i, storev[i]);
            }

            int start = 0;
            int end = storev.size();
            while (start < end) {
                int mid = (start + end)/2;
                if (value < storev[mid]) end = mid;
                else start = mid+1;
            }

            printf("Co-ordinates of start are = %d\n",start);
        }
};

UpperBound b;
int main(int argc, char **argv) {
    b.start();
    return 0;
}
