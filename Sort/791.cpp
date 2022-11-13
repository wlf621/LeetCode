class Solution {
public:
    string customSortString(string order, string s) {
        string ans(s);
        int sortList[26] = {0};
        for (int i = 0; i < order.size(); i++) {
            sortList[order[i] - 'a'] = i;
        }
        sort(ans.begin(), ans.end(), [&](char a, char b) -> bool {return sortList[a - 'a'] < sortList[b - 'a']; });
        return ans;
    }
};