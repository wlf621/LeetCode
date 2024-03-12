/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include "inc.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> yhTriangle(1, vector<int>(1, 1));
        int col = 2;
        for (int row = 2; row <= numRows; row++) {
            vector<int> rows(row);
            for (int i = 0; i < row; i++ ) {
                rows[i] = 0;
                if (i - 1 >= 0) {
                    rows[i] += yhTriangle[row - 2][i - 1];
                }
                if (i < row - 1) {
                    rows[i] += yhTriangle[row - 2][i];
                }
            }
            yhTriangle.push_back(rows);
        }
        return yhTriangle;
    }
};

// @lc code=end

