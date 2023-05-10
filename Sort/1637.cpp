#include "inc.h"

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans = 0;
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b){return a[0] <= b[0];});
        for (int i = 1; i < points.size(); i++) {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> points{{8,7},{9,9},{7,4},{9,7}};
    Solution sl;
    cout << sl.maxWidthOfVerticalArea(points);
    return 0;
}