/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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

// class Solution {
// public:
//     void preorder(TreeNode* cur, vector<int> &ans){
//         if (cur == nullptr) {
//             return;
//         }
//         ans.emplace_back(cur->val);
//         preorder(cur->left, ans);
//         preorder(cur->right, ans);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         preorder(root, ans);
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        stack<TreeNode*> st;
        TreeNode *cur = root;

        while(!st.empty() || cur != nullptr) {
            while (cur != nullptr) {
                st.push(cur);
                ans.emplace_back(cur->val);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
        return ans;
    }
};

// @lc code=end

