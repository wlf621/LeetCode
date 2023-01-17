#include "inc.h"

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int res = 101;
        vector<int> cMap(26, 0), targetMap(26, 0);
        for (auto c : s) cMap[c - 'a']++;
        for (auto c : target) targetMap[c - 'a']++;
        for (auto c : target) res = min(cMap[c - 'a'] / targetMap[c - 'a'], res);
        return res; 
    }
};

int main()
{
    vector<vector<string>> knowledge{{"name", "bob"}, {"age", "two"}};
    Solution sl;
    cout << sl.rearrangeCharacters("ilovecodingonleetcode", "code");
    return 0;
}