#include "inc.h"

class Solution {
public:
    int secondHighest(string s) {
        int num[10]{0};
        bool flag = false;
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num[c - '0'] = 1;
            }
        }

        for (int i = 9; i >= 0; i--) {
            if (num[i] !=0) {
                if (!flag) flag = true;
                else return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sl;
    cout << sl.secondHighest( "abc1111");
    return 0;
}