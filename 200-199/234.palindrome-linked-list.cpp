/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (37.07%)
 * Likes:    2025
 * Dislikes: 288
 * Total Accepted:    309.5K
 * Total Submissions: 831.5K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
lass Solution{
    public :
        bool isPalindrome(ListNode * head){
            auto fast = head;
auto slow = head;
while (fast && fast->next)
{
    slow = slow->next;
    fast = fast->next->next;
}
if (fast)
    slow = slow->next;
auto mid = reverseList(slow);
while (mid)
{
    if (mid->val != head->val)
        return false;
    mid = mid->next;
    head = head->next;
}
return true;
}
ListNode *reverseList(ListNode *head)
{
    ListNode dummy(-1);
    ListNode *p = head;

    while (p)
    {
        // lift up p
        ListNode *next = p->next;
        // insert
        p->next = dummy.next;
        dummy.next = p;
        p = next;
    }
    return dummy.next;
}
}
;
// @lc code=end
