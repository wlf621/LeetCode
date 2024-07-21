/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 * 
 * 实例1
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 实例1
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/?source=vscode
 */
#include "inc.h"
// @lc code=start

class Solution {
    int getKthMinNum(vector<int>& nums1, vector<int>& nums2, int k) {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 valueNums1 = nums1[k/2-1] 和 valueNums2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 valueNums1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 valueNums2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 value = min(valueNums1, valueNums2)，两个数组中小于等于 value 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 value 本身最大也只能是第 k-1 小的元素
         * 如果 value = valueNums1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 value = valueNums2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */

        int m = nums1.size(), n = nums2.size(), index1 = 0, index2 = 0;

        while (true) {
            //某一数组全部剔除
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            // 简单在两个数组都未全部剔除的情况下，理解每次最多排除K-1，最终k=1
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }
                   
            int newIndex1 = min(index1 + k / 2 - 1, m -1);
            int newIndex2 = min(index2 + k / 2 - 1, n -1);
            int valueNums1 = nums1[newIndex1];
            int valueNums2 = nums2[newIndex2];

            if (valueNums1 <= valueNums2) {
                k -= newIndex1 -index1 + 1;
                index1 = newIndex1 + 1;
            } else {
                k -= newIndex2 -index2 + 1;
                index2 = newIndex2 + 1;
            }

        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) % 2) {
            return getKthMinNum(nums1, nums2, (m + n) / 2 + 1);
        } else {
            return (getKthMinNum(nums1, nums2, (m + n) / 2) + getKthMinNum(nums1, nums2, (m + n) / 2 + 1)) / 2.0;
        }
    }
};
// @lc code=end

