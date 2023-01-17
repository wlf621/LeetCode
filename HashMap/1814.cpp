#include "inc.h"

constexpr double MOD = 1e9 + 7;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        long long res = 0;
        map<int, int> numMap;
        for (auto num : nums) {
            int tmp = 0, tnum = num;
            while (tnum > 0) {
                tmp *=10;
                tmp += tnum % 10;
                tnum /= 10;
            }
            numMap[num - tmp]++;
        }
        for (auto v : numMap) {
            v.second--;
            long long tmp = 0;
            while (v.second > 0) {
                tmp = (tmp + v.second) % (int)MOD;
                v.second--;
            }
            res = (res + tmp) % (int)MOD;
        }
        return res;
    }
};

int main()
{
    vector<int> nums{432835222,112141211,5408045,456281503,283322436,414281561,37773,286505682};
    Solution sl;
    cout << sl.countNicePairs(nums);
    return 0;
}