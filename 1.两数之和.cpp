/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
// #include "inc.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        for (int i = 0; i < nums.size(); i++) {
            int tar = target - nums[i];
            unordered_map<int, int>::iterator it = hashTable.find(tar);
            if (it != hashTable.end()) {
                return {it->second, i};
            }
            hashTable.insert(make_pair(nums[i], i));
        }
        return {};
    }
};
// @lc code=end

