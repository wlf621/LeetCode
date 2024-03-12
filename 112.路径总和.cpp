/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool dfs(TreeNode* cur, int val, int &targetSum) {
        if (cur == nullptr) {
            return false;
        }
        if (cur->left == nullptr && cur->right == nullptr) {
            return val + cur->val == targetSum;
        }
        return dfs(cur->left, val + cur->val, targetSum) || dfs(cur->right, val + cur->val, targetSum); 
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        return dfs(root, 0, targetSum);
    }
};
// @lc code=end

