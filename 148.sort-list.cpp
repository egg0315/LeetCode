/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
  ListNode *sortList(ListNode *head) { return mergeSort(head); }

  ListNode *mergeSort(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode dummy(-1);
    dummy.next = head;
    auto fast = &dummy;
    auto slow = &dummy;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    auto mid = slow->next;
    slow->next = NULL;
    auto left = mergeSort(head);
    auto right = mergeSort(mid);

    // merge
    return merge(left, right);
  }

  ListNode *merge(ListNode *p, ListNode *q) {
    ListNode dummy(0);
    auto cur = &dummy;
    while (p && q) {
      if (p->val < q->val) {
        cur->next = p;
        p = p->next;
      } else {
        cur->next = q;
        q = q->next;
      }
      cur = cur->next;
    }
    while (p) {
      cur->next = p;
      p = p->next;
      cur = cur->next;
    }
    while (q) {
      cur->next = q;
      q = q->next;
      cur = cur->next;
    }
    return dummy.next;
  }
};
