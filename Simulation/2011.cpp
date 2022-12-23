#include "inc.h"

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        map<string, int> operationMap{
            {"++X", 1}, {"X++", 1},
            {"--X", -1}, {"X--", -1}
        };
        for (auto s : operations) {
            ans += operationMap[s];
        }
        return ans;
    }
};

int main()
{
    Solution sl;
    vector<string> tmp = {"--X","X++","X++"};
    cout << sl.finalValueAfterOperations(tmp);
    return 0;
}