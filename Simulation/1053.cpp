#include "inc.h"

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        vector<int> ans(arr);
        int n = arr.size(), left, right, gap = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((arr[i] - arr[j] > 0) && (arr[i] - arr[j] <= gap)) {
                    gap = arr[i] - arr[j];
                    left = i;
                    right = j;
                }
            }
        }
        if (gap != INT_MAX) {
            int tmp = ans[left];
            ans[left] = ans[right];
            ans[right] = tmp;
        }
        return ans;
    }
};

int main()
{
    vector<int> arr{1,1,5};
    Solution sl;
    cout << sl.prevPermOpt1(arr);
    return 0;
}