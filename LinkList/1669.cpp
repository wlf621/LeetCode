#include "inc.h"

// 未释放内存，存在内存泄漏
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *prevOfa = nullptr, *nextOfb = nullptr, *pwork = list1;
        while (--a) {
            pwork = pwork->next;
            b--;
        }
        prevOfa = pwork;
        b++;
        while (b--) pwork = pwork->next;
        nextOfb = pwork;
        pwork = list2;
        prevOfa->next = pwork;
        while (pwork->next != nullptr) {
            pwork = pwork->next;
        }
        pwork->next = nextOfb;
        return list1;
    }
};

int main()
{
    Solution sl;
    cout << sl.mergeInBetween( "abc1111");
    return 0;
}