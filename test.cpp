/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
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

int main() {
    Solution sl;
    TreeNode a(3, nullptr, nullptr);
    TreeNode e(4, nullptr, nullptr);
    TreeNode b(2, &a, &e);
    TreeNode root(1, nullptr, &b);
    sl.isHappy(19);
}
