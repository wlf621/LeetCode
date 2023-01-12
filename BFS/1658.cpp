#include "inc.h"

typedef struct tagNode {
    int l;
    int r;
    int val;
    int step;
} Node;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        queue<Node> que;
        Node front = {1, nums.size() - 1, x - nums[0], 1}, end = {0, nums.size() - 2, x - nums[nums.size() - 1], 1};
        que.push(front);
        que.push(end);

        while(!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; i++) {
                Node t = que.front();
                que.pop();
                if (t.val == 0) {
                    return t.step;
                }

                if (t.l > t.r || t.val < 0) {
                    continue;
                }

                if (t.l == t.r) {
                    que.push(Node{t.l + 1, t.r, t.val - nums[t.l], t.step + 1});
                } else {
                    que.push(Node{t.l + 1, t.r, t.val - nums[t.l], t.step + 1});
                    que.push(Node{t.l, t.r - 1, t.val - nums[t.r], t.step + 1});
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution sl;
    vector<int> nums{1241,8769,9151,3211,2314,8007,3713,5835,2176,8227,5251,9229,904,1899,5513,7878,8663,3804,2685,3501,1204,9742,2578,8849,1120,4687,5902,9929,6769,8171,5150,1343,9619,3973,3273,6427,47,8701,2741,7402,1412,2223,8152,805,6726,9128,2794,7137,6725,4279,7200,5582,9583,7443,6573,7221,1423,4859,2608,3772,7437,2581,975,3893,9172,3,3113,2978,9300,6029,4958,229,4630,653,1421,5512,5392,7287,8643,4495,2640,8047,7268,3878,6010,8070,7560,8931,76,6502,5952,4871,5986,4935,3015,8263,7497,8153,384,1136};
    cout << sl.minOperations(nums, 894887480);
    return 0;
}