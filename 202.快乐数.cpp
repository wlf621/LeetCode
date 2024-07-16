/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include "inc.h"
// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        long ans = n, temp;
        unordered_set<long> h;
        while (ans != 1 && h.count(ans) == 0) {
            temp = ans;
            h.insert(ans);
            ans = 0;
            while (temp != 0) {
                ans += (temp % 10) * (temp % 10);
                temp /= 10;
            }
        }
        return ans == 1;
    }
};
// @lc code=end

