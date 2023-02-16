#include "inc.h"

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> cnt(101, 0), ans(2, 0);
        for (auto num : nums) {
            cnt[num]++;
        }
        for (int i = 0; i < cnt.size(); i++) {
            ans[0] += (cnt[i] / 2);
            ans[1] += (cnt[i] % 2);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums{1,3,2,1,3,2,2};
    Solution sl;
    cout << sl.numberOfPairs(nums);
    return 0;
}