#include "inc.h"

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int word1Index = 0, word2Index = 0;
        string ans;
        while (word1Index < word1.size() && word2Index < word2.size()) {
            if (word1[word1Index] < word2[word2Index]) {
                ans.push_back(word2[word2Index]);
                word2Index++;
            } else if (word1[word1Index] > word2[word2Index]) {
                ans.push_back(word1[word1Index]);
                word1Index++;
            } else {
                int tmp1 = word1Index, tmp2 = word2Index;
                while (tmp1 < word1.size() && tmp2 < word2.size() && word1[tmp1] == word2[tmp2]) {
                    tmp1++;
                    tmp2++;
                }
                if (word1[tmp1] > word2[tmp2]) {
                    ans.push_back(word1[word1Index]);
                    word1Index++;
                } else {
                    ans.push_back(word2[word2Index]);
                    word2Index++;
                }
            }
        }
        ans.append(word1.substr(word1Index));
        ans.append(word2.substr(word2Index));
        return ans;
    }
};

int main()
{
    Solution sl;
    cout << sl.largestMerge("guguuuuuuuuuuuuuuguguuuuguug", "gguggggggguuggguugggggg");
    return 0;
}