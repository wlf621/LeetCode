#include "inc.h"
constexpr long long MOD = 1e9 + 7;

class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0, r = 0, n = s.size();
        while (r < n) {
            int l = r;
            while (l < n && s[l] == s[r]) l++;
            ans += ((((l - r) + 1) * (l - r) / 2) % MOD);
            r = l;
        }
        return ans % MOD;
    }
};

int main()
{
    Solution sl;
    cout << sl.countHomogenous("www");
    return 0;
}