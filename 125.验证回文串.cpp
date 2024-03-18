/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include "inc.h"
// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            while (l <= r && !isalnum(s[l]) ) {
                l++;
            }
            while (l <= r && !isalnum(s[r]) ) {
                r--;
            }
             if (l <= r) {
                if (tolower(s[l]) != tolower(s[r])) {
                    return false;
                }
                l++;
                r--;
            }
        }
        return true;
    }
};
// @lc code=end

