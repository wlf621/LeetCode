/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#include "inc.h"
// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (c == 0) return digits;
            if (digits[i] + c >= 10) {
                digits[i] = (digits[i] + c) % 10;
                c = 1;
            } else {
                digits[i] = (digits[i] + c) % 10;
                c = 0;
            }
        }
        if (c == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
// @lc code=end

