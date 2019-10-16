/*
 * @lc app=leetcode id=854 lang=cpp
 *
 * [854] K-Similar Strings
 */
class Solution {
public:
  int kSimilarity(string A, string B) {
    if (A == B)
      return 0;
    int K = 0, n = A.size();

    queue<string> q;
    unordered_set<string> seen;
    q.push(A);
    seen.insert(A);
    string a;
    while (!q.empty()) {
      int sz = q.size();
      ++K;
      for (int k = 0; k < sz; ++k) {
        auto t = q.front();
        q.pop();
        int i = 0;
        while (t[i] == B[i])
          ++i;
        // swap i, j
        for (int j = i + 1; j < n; ++j) {
          // pointless swap
          if (t[i] == t[j] || t[i] != B[j])
            continue;
          swap(t[i], t[j]);
          if (t == B)
            return K;
          if (seen.count(t) == 0) {
            seen.insert(t);
            q.push(t);
          }
          swap(t[i], t[j]);
        }
      }
    }
    return K;
  }
};
