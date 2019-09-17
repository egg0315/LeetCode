/*
 * @lc app=leetcode id=426 lang=cpp
 *
 * [426] Convert Binary Search Tree to Sorted Doubly Linked List
 * tag : tree
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
  // inorder traversal
  Node *treeToDoublyList(Node *root) {
    Node *head = NULL;
    Node *last = NULL;
    if (!root)
      return NULL;
    stack<Node *> st;
    auto p = root;
    while (!st.empty() || p) {
      if (p) {
        st.push(p);
        p = p->left;
      } else {
        p = st.top();
        st.pop();
        if (!last) {
          head = p;
        }
        if (last) {
          last->right = p;
          p->left = last;
        }
        last = p;
        p = p->right;
      }
    }
    head->left = last;
    last->right = head;
    return head;
  }
};
