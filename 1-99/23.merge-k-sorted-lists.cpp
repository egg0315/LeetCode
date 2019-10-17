/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (36.17%)
 * Likes:    3073
 * Dislikes: 204
 * Total Accepted:    470.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        return merge(lists, 0, n - 1);
    }

    ListNode *merge(vector<ListNode *> &lists, int i, int j)
    {
        if (i == j)
            return lists[i];
        if (i > j)
            return nullptr;
        int mid = (i + j) / 2;
        auto left = merge(lists, i, mid);
        auto right = merge(lists, mid + 1, j);
        return mergeTwoList(left, right);
    }

    ListNode *mergeTwoList(ListNode *left, ListNode *right)
    {
        ListNode dummy(-1);
        auto p = &dummy;
        while (left && right)
        {
            if (left->val < right->val)
            {
                p->next = left;
                left = left->next;
            }
            else
            {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        auto remain = left ? left : right;
        while (remain)
        {
            p->next = remain;
            remain = remain->next;
            p = p->next;
        }
        return dummy.next;
    }
};
// @lc code=end
