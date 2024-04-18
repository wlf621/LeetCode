/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = 0, ans;
        for (int c : nums) {
            if (num == 0) {
                ans = c;
                num++;
            } else {
                if (ans != c) {
                    num--;
                } else {
                    num++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

