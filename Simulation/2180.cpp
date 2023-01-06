#include "inc.h"

class Solution {
public:
    int countEven(int num) {
        int sum = 0;
        for (int i = 1; i <= num; i++) {
            int t = i, cnt = 0;
            while (t > 0) {
                cnt += t % 10;
                t /= 10;
            }
            sum += ((cnt & 1) ^ 1);
        }
        return sum;
    }
};

int main()
{
    Solution sl;
    cout << sl.countEven(30);
    return 0;
}