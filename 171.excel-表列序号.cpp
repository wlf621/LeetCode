/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */
#include "inc.h"
// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ans = 0, s = 1;
        for (int i = columnTitle.size() - 1; i >= 0; i--) {
            ans += (columnTitle[i] - 'A' + 1) * s;
            s = s*26;
        }
        return ans;
    }
};
// @lc code=end

