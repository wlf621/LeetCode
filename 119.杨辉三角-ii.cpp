/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */
#include "inc.h"
// @lc code=start
// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {
//         vector<int> cur, pre;
//         for (int i = 0; i <= rowIndex; i++) {
//             cur.resize(i + 1);
//             cur[0] = cur[i] = 1;
//             for (int j = 1; j < i; j++) {
//                 cur[j] = pre[j - 1] + pre[j];
//             }
//             pre = cur;
//         }
//         return cur;
//     }
// };

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++) {
            cur[0] = cur[i] = 1;
            for (int j = i - 1; j > 0; j--) {
                cur[j] += cur[j - 1];
            }
        }
        return cur;
    }
};
// @lc code=end

