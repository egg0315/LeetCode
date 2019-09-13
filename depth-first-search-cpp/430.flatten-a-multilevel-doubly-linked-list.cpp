/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 * TODO: use stack, iterative solution
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
  Node *flatten(Node *head) {
    if (!head)
      return NULL;
    auto p = head;
    while (p && !p->child) {
      p = p->next;
    }
    if (p) {
      auto tmp = flatten(p->next);
      p->child->prev = p;
      p->next = flatten(p->child);
      p->child = NULL;
      while (p->next) {
        p = p->next;
      }
      if (tmp)
        tmp->prev = p;
      p->next = tmp;
    }
    return head;
  }
};
