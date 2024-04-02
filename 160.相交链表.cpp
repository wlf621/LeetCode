/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
#include "inc.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 0, n = 0;
        ListNode *curA, *curB;
        curA = headA;
        while (curA != nullptr) {
            curA = curA->next;
            m++;
        }
        curB = headB;
        while (curB != nullptr) {
            curB = curB->next;
            n++;
        }
        curA = headA;
        curB = headB;
        while (m > n) {
            curA = curA->next;
            m--;
        }
        while (m < n) {
            curB = curB->next;
            n--;
        }
        while (curA != curB) {
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }
};
// @lc code=end

