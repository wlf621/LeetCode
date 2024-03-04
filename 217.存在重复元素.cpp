/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
// #include "inc.h"
// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> h;
        for (int i = 0; i < nums.size(); i++) {
            if (h.find(nums[i]) != h.end()) {
                return true;
            }
            h.emplace(nums[i]);
        }
        return false;
    }
};
// @lc code=end

