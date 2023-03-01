#include "inc.h"

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0 ; j < n - 2; j++) {
                int tmp = 0;
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        tmp = max(tmp, grid[k][l]);
                    }
                }
                ans[i][j] = tmp;
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> nums{{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
    Solution sl;
    sl.largestLocal(nums);
    return 0;
}