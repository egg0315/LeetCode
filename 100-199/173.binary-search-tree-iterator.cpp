/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
  BSTIterator(TreeNode *root) {
    while (root) {
      st.push(root);
      root = root->left;
    }
  }

  /** @return the next smallest number */
  int next() {
    int res = st.top()->val;
    auto cur = st.top();
    st.pop();
    if (cur->right) {
      cur = cur->right;
      while (cur) {
        st.push(cur);
        cur = cur->left;
      }
    }
    return res;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return st.size(); }

private:
  stack<TreeNode *> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
