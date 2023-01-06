#include "inc.h"

struct Trie
{
    int sum;
    array<Trie*, 2> childs{nullptr, nullptr};
    Trie(){this->sum = 0;}
};


class Solution {
    Trie* root = nullptr;
    static constexpr int HIGH_BIT = 14;

    void add(int num) {
        Trie* cur = root;
        for (int k = HIGH_BIT;k >= 0; k--) {
            int bit = (num >> k) & 1;
            if (cur->childs[bit] == nullptr) {
                cur->childs[bit] = new Trie();
            }
            cur = cur->childs[bit];
            cur->sum++;
        }
    }

    int get(int num, int x) {
        Trie* cur = root;
        int sum = 0;
        for (int k = HIGH_BIT;k >= 0; k--) {
            int r = (num >> k) & 1;
            if ((x >> k) & 1) {
                if (cur->childs[r] != nullptr) {
                    sum += cur->childs[r]->sum;
                }
                if (cur->childs[r ^ 1] == nullptr) {
                    return sum;
                }
                cur = cur->childs[r ^ 1];
            } else {
                if (cur->childs[r] == nullptr) {
                    return sum;
                }
                cur = cur->childs[r];
            }
        }
        sum += cur->sum; // 相等的情况
        return sum;
    }

    int f(vector<int>& nums, int x) {
        root = new Trie();
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            add(nums[i - 1]);
            res += get(nums[i], x);
        }
        return res;
    }
public:
    int countPairs(vector<int>& nums, int low, int high) {
        return f(nums, high) - f(nums, low - 1);
    }
};

int main()
{
    vector<int> nums{1, 4, 2, 7};
    Solution sl;
    cout << sl.countPairs(nums, 3, 6);
    return 0;
}