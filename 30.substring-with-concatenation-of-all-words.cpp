/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 * Tag: two pointer, hash map, string
 */
class Solution {
public:
  unordered_map<string, int> need;
  unordered_map<string, int> count;
  vector<int> findSubstring(string s, vector<string> &words) {
    if (!words.size())
      return {};
    int n = words.size();
    for (auto &w : words) {
      need[w]++;
    }
    int sz = words[0].size();

    vector<int> res;
    for (int offset = 0; offset < sz; ++offset) {
      int k = 0;
      count.clear();
      for (; offset + k * sz + sz <= s.size(); ++k) {
        // start of the string k*sz,  last of string (k+n)*sz-1
        // string to delete s.substr((k-n)*sz, sz)
        if (k >= n) {
          count[s.substr(offset + (k - n) * sz, sz)]--;
        }
        count[s.substr(offset + k * sz, sz)]++;
        if (check()) {
          res.push_back(offset + (k - n + 1) * sz);
        }
      }
    }

    return res;
  }

  bool check() {
    for (auto &[s, cnt] : need) {
      if (count[s] != cnt)
        return false;
    }
    return true;
  }
};
