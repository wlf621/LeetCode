#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int ans = 0;
        vector<vector<int>> matrix(n, vector<int>(n, 1));
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(4, 0)));
        for (auto node : mines) {
            matrix[node[0]][node[1]] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) dp[i][j][0] = ((matrix[i][j] == 1) ? 1 : 0);
                else dp[i][j][0] = ((matrix[i][j] == 1) ? dp[i][j - 1][0] + 1 : 0);
            }
            for (int j = n - 1; j >= 0; j--) {
                if (j == n - 1) dp[i][j][1] = ((matrix[i][j] == 1) ? 1 : 0);
                else dp[i][j][1] = ((matrix[i][j] == 1) ? dp[i][j + 1][1] + 1 : 0);
            }
            for (int j = 0; j < n; j++) {
                if (j == 0) dp[j][i][2] = ((matrix[j][i] == 1) ? 1 : 0);
                else dp[j][i][2] = ((matrix[j][i] == 1) ? dp[j - 1][i][2] + 1 : 0);
            }
            for (int j = n - 1; j >= 0; j--) {
                if (j == n - 1) dp[j][i][3] = ((matrix[j][i] == 1) ? 1 : 0);
                else dp[j][i][3] = ((matrix[j][i] == 1) ? dp[j + 1][i][3] + 1 : 0);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = n;
                for (int k = 0; k < 4; k++) {
                   tmp = min(tmp, dp[i][j][k]);
                }
                ans = max(ans, tmp);
            }
        }

        return ans;
    }
};

/*
* 0 0
* 0 1
*/
int main()
{
    Solution sl;
    vector<vector<int>> nums{{0, 0}, {0, 1}, {1, 0}};
    vector<string> words {"a","b","c","ab","ac","bc","abc"};
    cout << sl.orderOfLargestPlusSign(2, nums);
    return 0;
}