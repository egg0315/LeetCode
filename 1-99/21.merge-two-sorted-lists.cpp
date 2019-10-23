/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (49.48%)
 * Likes:    2782
 * Dislikes: 407
 * Total Accepted:    719.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        ListNode *p1 = l1;
        ListNode *p2 = l2;

        while (p1 && p2)
        {
            if (p1->val < p2->val)
            {
                cur->next = p1;
                p1 = p1->next;
            }
            else
            {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
            cur->next = nullptr;
        }
        if (p1)
        {
            cur->next = p1;
        }
        else
        {
            cur->next = p2;
        }

        return dummy->next;
    }
};
// @lc code=end
