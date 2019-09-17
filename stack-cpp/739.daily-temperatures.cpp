/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &t) {
    int n = t.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && t[st.top()] < t[i]) {
        res[st.top()] = i - st.top();
        st.pop();
      }
      st.push(i);
    }
    return res;
  }
};
