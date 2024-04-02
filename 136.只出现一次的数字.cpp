/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include "inc.h"
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int n : nums) {
            ans ^= n;
        }
        return ans;
    }
};
// @lc code=end

