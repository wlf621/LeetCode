/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 * 整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
 * 
 * 例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
 * 整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
 * 
 * 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
 * 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
 * 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
 * 给你一个整数数组 nums ，找出 nums 的下一个排列。
 * 
 * 必须 原地 修改，只允许使用额外常数空间。
 * 
 *  
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3]
 * 输出：[1,3,2]
 * 示例 2：
 * 
 * 输入：nums = [3,2,1]
 * 输出：[1,2,3]
 * 示例 3：
 * 
 * 输入：nums = [1,1,5]
 * 输出：[1,5,1]
 * 
 */
#include "inc.h"
// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 需要将一个左边的「较小数」与一个右边的「较大数」交换，以能够让当前排列变大，从而得到下一个排列。
        // 同时我们要让这个「较小数」尽量靠右，而「较大数」尽可能小。
        // 当交换完成后，「较大数」右边的数需要按照升序重新排列。
        // 这样可以在保证新排列大于原来排列的情况下，使变大的幅度尽可能小。
        int n = nums.size(), indexMin = -1, indexMax = -1;

        // 从后向前查找第一对nums[i - 1] < nums[i], 由于找到这个对之前一直是nums[i] >= nums[i + 1]，因此nums[i, .., n-1]是下降序列
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                indexMin = i - 1;
                break;
            }
        }
        cout << indexMin << endl;
        if (indexMin > -1) {
            // 由于nums[indexMin + 1, .., n-1]是下降序列且，从后向前查找第一个大于nums[indexMin]即使最小的大于nums[indexMin]的数（较大数）
            // 交换后记录较大数位置
            for (int i = n - 1; i > 0; i--) {
                if (nums[i] > nums[indexMin]) {
                    swap(nums[indexMin], nums[i]);
                    indexMax = i;
                    break;
                }
            }
        }
        cout << indexMax;
        // 较小数后面的数为下降序列，反转后续数字使其变为升序
        reverse(nums.begin() + indexMin + 1, nums.end());
    }
};
// @lc code=end

