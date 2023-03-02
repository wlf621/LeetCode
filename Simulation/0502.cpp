#include "inc.h"

class Solution {
public:
    string printBin(double num) {
        string ans = "0.";
        while (ans.size() < 32 && num != 0) {
            num = num * 2;
            if (num >= 1) {
                ans.push_back('1');
            } else {
                ans.push_back('0');
            }
            num = num - int(num);
        }
        return ans.size() >= 32 ? "ERROR" : ans;
    }
};

int main()
{
    Solution sl;
    cout << sl.printBin(0.1);
    return 0;
}