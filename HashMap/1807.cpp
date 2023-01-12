#include "inc.h"

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res = "";
        map<string, string> knowledgeMap;
        for (auto keys : knowledge) {
            knowledgeMap[keys[0]] = keys[1];
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                string key = "";
                i++;
                while (s[i] != ')') {
                    key.push_back(s[i]);
                    i++;
                }
                if (knowledgeMap.count(key) != 0) {
                    res += knowledgeMap[key];
                } else {
                    res += "?";
                }
            } else {
                res += s[i];
            }
        }

        return res;
    }
};

int main()
{
    vector<vector<string>> knowledge{{"name", "bob"}, {"age", "two"}};
    Solution sl;
    cout << sl.evaluate("(name)is(age)yearsold", knowledge);
    return 0;
}