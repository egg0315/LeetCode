/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
  int maxDepth(Node *root) {
    if (!root)
      return 0;
    int tmp = 0;
    for (auto ch : root->children)
      tmp = max(tmp, maxDepth(ch));
    return tmp + 1;
  }
};
