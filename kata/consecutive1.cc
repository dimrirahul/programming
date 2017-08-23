#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        size_t pos = 0;
        int res = 0;
        while (pos < nums.size()) {
            res = max(res, getLen(nums, pos));
        }
        return res; 
    }
    
    int getLen(vector<int>& nums, size_t& pos) {
        int len = 0;
        while (pos < nums.size() && nums[pos] == 0) pos++;
        while (pos < nums.size() && nums[pos] == 1) {
            pos++;
            len++;
        }
        return len;
    }
};

int main() {
    Solution s;
    vector<int> v {1,0,1,1,0,1};
    cout << s.findMaxConsecutiveOnes(v);
    return 0;
}
