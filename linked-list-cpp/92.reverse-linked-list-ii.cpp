/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 * tag : list
 */
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
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *h, *t;
    h = t = &dummy;
    // take node from m insert it after node n
    for (int i = 0; i < n; ++i) {
      t = t->next;
    }
    for (int i = 0; i < m - 1; ++i) {
      h = h->next;
    }
    while (h->next != t) {
      // take next of head
      auto tmp = h->next;
      h->next = tmp->next;
      tmp->next = t->next;
      t->next = tmp;
    }
    return dummy.next;
  }
};
