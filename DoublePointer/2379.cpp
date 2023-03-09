#include "inc.h"
constexpr long long MOD = 1e9 + 7;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0, ans = INT_MAX;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                cnt++;
            }
        }
        ans = min(cnt, ans);
        for (int i = 1; i + k - 1 < blocks.size(); i++) {
            if (blocks[i - 1] == 'W') {
                cnt--;
            }
            if (blocks[i + k - 1] == 'W') {
                cnt++;
            }
            ans = min(cnt, ans);
        }
        return ans;
    }
};

int main()
{
    Solution sl;
    cout << sl.minimumRecolors("WBWBBBW", 2);
    return 0;
}