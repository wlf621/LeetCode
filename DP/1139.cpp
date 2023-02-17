#include "inc.h"

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j<= n; j++) {
                if (grid[i - 1][j - 1] == 0) {
                    continue;
                }
                dp[i][j][0] = dp[i][j - 1][0] + 1;
                dp[i][j][1] = dp[i -1][j][1] + 1;
            }
        }
        for (int i = m; i > 0; i--) {
            for (int j = n; j > 0; j--) {
                int tmp_max = min(dp[i][j][0], dp[i][j][1]);
                if (tmp_max <= ans) {
                    continue;
                }
                for (; tmp_max > ans; tmp_max--) {
                    if (dp[i - tmp_max + 1][j][0] >= tmp_max && dp[i][j - tmp_max + 1][1] >= tmp_max) {
                        ans = tmp_max;
                        break;
                    }
                }
            }
        }
        return ans * ans;
    }
};

int main()
{
    vector<vector<int>> grid{{1,1,1},{1,0,1},{1,1,1}};
    Solution sl;
    sl.largest1BorderedSquare(grid);
    return 0;
}