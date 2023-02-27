#include "inc.h"

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int case1 = 0, case2 = 0, n = nums.size();
        for (int i = 0; i < nums.size(); i += 2) {
            int tmp;
            if (i - 1 >= 0) tmp = nums[i - 1];
            if (i + 1 < n) tmp = min(tmp, nums[i + 1]);
            case1 += ((nums[i] - tmp + 1) > 0 ? (nums[i] - tmp + 1) : 0);
        }
        for (int i = 1; i < nums.size(); i += 2) {
            int tmp;
            if (i - 1 >= 0) tmp = nums[i - 1];
            if (i + 1 < n) tmp = min(tmp, nums[i + 1]);
            case2 += ((nums[i] - tmp + 1) > 0 ? (nums[i] - tmp + 1) : 0);
        }
        return min(case1, case2);
    }
};

int main()
{
    vector<int> nums{9,6,1,6,2};
    Solution sl;
    cout << sl.movesToMakeZigzag(nums);
    return 0;
}