#include "inc.h"

class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0, bCnt = 0;
        for (auto c : s) {
            if (c == 'a') {
                ans = min(ans +1, bCnt);
            }
            else bCnt++;
        }
        return ans;
    }
};

int main()
{
    string s = "";
    Solution sl;
    sl.minimumDeletions(s);
    return 0;
}