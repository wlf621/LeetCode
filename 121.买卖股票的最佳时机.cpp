/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include "inc.h"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            sum += (prices[i] - prices[i - 1]);
            maxProfit = max(maxProfit, sum);
            if (sum < 0) sum = 0;
        }
        return maxProfit;
    }
};
// @lc code=end

