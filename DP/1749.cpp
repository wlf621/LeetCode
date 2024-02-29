#include "inc.h"

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxA = 0, minB = INT_MAX, sumA = 0, sumB = 0;
        for(auto num : nums) {
            if (sumA + num < 0) sumA = 0;
            else sumA += num;
            if (sumB + num > 0) sumB = 0;
            else sumB += num;
            maxA = max(maxA, sumA);
            minB = min(minB, sumB);
        }
        return max(abs(maxA), abs(minB));
    }
};

int main()
{
    string s = "";
    vector<int> nums{1,-3,2,3,-4};
    Solution sl;
    sl.maxAbsoluteSum(nums);
    return 0;
}