/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (46.79%)
 * Likes:    1463
 * Dislikes: 131
 * Total Accepted:    367.5K
 * Total Submissions: 785.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode dummy(-1);
        dummy.next = head;

        ListNode *p = &dummy;

        while (p->next && p->next->next)
        {

            auto temp = p->next;
            p->next = p->next->next;
            temp->next = p->next->next;
            p->next->next = temp;

            p = p->next->next;
        }

        return dummy.next;
    }
};
// @lc code=end
