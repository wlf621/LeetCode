#include "inc.h"

constexpr double MOD = 1e9 + 7;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int> seen;
        int x = 1 % k;
        while (x && !seen.count(x)) {
            seen.insert(x);
            x = (x * 10 + 1) % k;
        }
        return x == 0 ? seen.size() + 1 : -1;
    }
};

int main()
{
    Solution sl;
    cout << sl.smallestRepunitDivByK(3);
    return 0;
}