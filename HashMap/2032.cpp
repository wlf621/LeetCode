#include "inc.h"

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> ans;
        short numsMap[101]{0};
        for (auto v : nums1) {
            numsMap[v] |= 1; 
        }
        for (auto v : nums2) {
            numsMap[v] |= 2; 
        }
        for (auto v : nums3) {
            numsMap[v] |= 4; 
        }
        for (int i = 1; i <= 100; i++) {
            if (((numsMap[i] & 3) == 3) || ((numsMap[i] & 6) == 6) || ((numsMap[i] & 5) == 5)) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};