/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
#include "inc.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* cur, int dep, int &maxD) {
        if (cur == nullptr) {
            return;
        }
        if (dep > maxD) {
            maxD = dep;
        }
        if (cur->left != nullptr) {
            dfs(cur->left, dep + 1, maxD);
        }
        if (cur->right != nullptr) {
            dfs(cur->right, dep + 1, maxD);
        }
    }

    int maxDepth(TreeNode* root) {
        int maxD = 0;
        dfs(root, 1, maxD);
        return maxD;
    }
};
// @lc code=end

