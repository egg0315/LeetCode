/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (34.14%)
 * Likes:    1066
 * Dislikes: 88
 * Total Accepted:    204.7K
 * Total Submissions: 596K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode dummy(-1);
        // write pointer
        auto wr = &dummy;
        auto p = head;
        while (p)
        {
            bool duplicate = false;
            while (p && p->next && p->val == p->next->val)
            {
                duplicate = true;
                p = p->next;
            }
            if (!duplicate)
            {
                wr->next = p;
                wr = wr->next;
            }
            auto tmp = p->next;
            // [1,2,2]
            p->next = nullptr;
            p = tmp;
        }
        return dummy.next;
    }
};
// @lc code=end
