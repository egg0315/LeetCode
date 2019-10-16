/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */
class Solution {
public:
  vector<int> asteroidCollision(vector<int> &A) {
    vector<int> st;
    for (auto &s : A) {
      if (st.empty() || s > 0) {
        st.push_back(s);
      } else {
        while (true) {
          // both left
          if (st.back() < 0) {
            st.push_back(s);
            break;
          }
          // same size
          if (st.back() + s == 0) {
            st.pop_back();
            break;
          }
          // smaller
          if (st.back() + s > 0) {
            break;
          }
          st.pop_back();
          // no other asteroid
          if (st.empty()) {
            st.push_back(s);
            break;
          }
        }
      }
    }
    return st;
  }
};
