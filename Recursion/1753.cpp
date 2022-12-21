#include "inc.h"
//超时未AC，提示：贪心

int st[3][3]{{1, 0, 1}, {1, 1, 0}, {0, 1, 1}};

class Solution {
    int ans_max = 0;
    void helper(int &a, int &b, int &c, int &&step) {
        if (a < 0 || b < 0 || c < 0) {
            return;
        }
        if ((a == 0 && b == 0) || (a == 0 && c == 0) || (b == 0 && c == 0)) {
            ans_max = max(ans_max, step);
            return;
        }
        for (int i = 0; i < 3; i++) {
            a -= st[i][0]; b -= st[i][1]; c -= st[i][2];
            helper(a, b, c, step + 1);
            a += st[i][0]; b += st[i][1]; c += st[i][2];
        }
    }
public:
    int maximumScore(int a, int b, int c) {
        helper(a, b, c, 0);
        return ans_max;
    }
};

int main()
{
    Solution sl;
    cout << sl.maximumScore(8, 16, 22);
    return 0;
}