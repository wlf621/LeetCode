class Solution {
public:
    bool check(vector<int>& nums) {
        bool flag = false;
        int pre = nums[0];
        int left_max = pre, left_min = pre;
        int right_min = 0, right_max = 0;
        for (int cur : nums) {
            if (flag == false) {
                if (cur < pre) {
                    flag = true;
                    right_min = cur;
                    right_max = cur;
                } else {
                    left_max = max(left_max, cur);
                    left_min = min(left_min, cur);
                }
            } else {
                if (cur < pre) return false;
                right_min = min(right_min, cur);
                right_max = max(right_max, cur);
            }
            pre = cur;
        }
        return left_max <= right_min || left_min >= right_max;
    }
};