/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 * tag : list, implementation
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
  void reorderList(ListNode *head) {
    if (!head || !head->next)
      return;
    ListNode *p = head;
    ListNode *mid = head;
    while (p && p->next) {
      p = p->next->next;
      mid = mid->next;
    }
    p = reverse(mid->next);
    mid->next = NULL;
    // interleaving
    ListNode *odd = head;
    while (p) {
      auto tmp = p;
      p = p->next;
      tmp->next = odd->next;
      odd->next = tmp;
      odd = odd->next->next;
    }
  }
  ListNode *reverse(ListNode *head) {
    if (!head)
      return NULL;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *end = head;
    while (end->next) {
      end = end->next;
    }
    while (dummy.next != end) {
      auto tmp = dummy.next;
      dummy.next = dummy.next->next;
      tmp->next = end->next;
      end->next = tmp;
    }
    return dummy.next;
  }
};
