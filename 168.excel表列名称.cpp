/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

#include "inc.h"
// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            ans.push_back('A' + (columnNumber - 1) % 26);
            columnNumber = (columnNumber - 1)/26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

