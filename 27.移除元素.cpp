/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
// #include "inc.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = 0;
        while (r < nums.size()) {
            if (nums[r] == val) {
                r++;
            } else {
                nums[l++] = nums[r++];
            }
        }
        return l;
    }
};
// @lc code=end

