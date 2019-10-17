/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (37.96%)
 * Likes:    1445
 * Dislikes: 290
 * Total Accepted:    211.4K
 * Total Submissions: 553.4K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
    ListNode *reverseKGroup(ListNode *head, int K)
    {
        ListNode dummy(-1);
        dummy.next = head;
        auto p = &dummy;
        auto anchor = p;
        while (true)
        {
            int k = 0;
            while (k < K && anchor && anchor->next != nullptr)
            {
                anchor = anchor->next;
                ++k;
            }
            if (k != K)
                break;
            auto next_anchor = p->next;
            // reverse
            while (p->next != anchor)
            {
                // strip off p->next;
                auto tmp = p->next;
                p->next = p->next->next;
                // insert
                tmp->next = anchor->next;
                anchor->next = tmp;
            }
            p = anchor = next_anchor;
        }
        return dummy.next;
    }
};
// @lc code=end
