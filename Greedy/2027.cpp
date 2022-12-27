#include "inc.h"

class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0;
        for (int i = 0; i < s.size();) {
            if (s[i] == 'X') {
                ans++;
                i += 3;
            } else {
                i++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sl;
    cout << sl.minimumMoves("XX0X");
    return 0;
}