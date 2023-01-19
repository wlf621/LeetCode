#include "inc.h"

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) return false;
        bool isContainUper = false, isContainLower = false, isContainNum = false, isContainSpecial = false, isContineSame = false;
        char pre = 0;
        for (auto c : password) {
            if (c == pre) isContineSame = true;
            if ('a' <= c && c <= 'z') isContainLower = true;
            else if ('A' <= c && c <= 'Z') isContainUper = true;
            else if ('0' <= c && c <= '9') isContainNum = true;
            else isContainSpecial = true;
            pre = c;  
        } 
        return isContainUper && isContainLower && isContainNum && isContainSpecial && !isContineSame;
    }
};

int main()
{
    Solution sl;
    cout << sl.strongPasswordCheckerII("11A!A!Aa");
    return 0;
}