/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */
class Solution {
public:
  string simplifyPath(string path) {
    string tmp;
    vector<string> st;
    stringstream in(path);
    while (getline(in, tmp, '/')) {
      // consecutive / or . means current directory
      if (tmp == "" || tmp == ".") {
        continue;
      } else if (tmp == ".." && !st.empty())
        st.pop_back();
      else if (tmp != "..") {
        st.push_back(tmp);
      }
    }
    string res;
    for (const auto &s : st)
      res += '/' + s;
    return res == "" ? "/" : res;
  }
};
