/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
// #include "inc.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int now = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[now] = nums[i];
                now++;
            }
        }

        return now;
    }
};
// @lc code=end

