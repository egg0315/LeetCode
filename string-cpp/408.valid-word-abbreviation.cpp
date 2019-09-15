/*
 * @lc app=leetcode id=408 lang=cpp
 *
 * [408] Valid Word Abbreviation
 * tag : string
 */
class Solution {
public:
  bool validWordAbbreviation(string word, string abbr) {
    int i = 0, j = 0, cnt = 0;
    for (int i = 0; i < abbr.size(); ++i) {
      if (isdigit(abbr[i])) {
        // check leading zero
        if (abbr[i] == '0' && cnt == 0)
          return false;
        cnt = cnt * 10 + abbr[i] - '0';
      } else {
        j += cnt;
        cnt = 0;
        if (j >= word.size() || word[j] != abbr[i]) {
          return false;
        }
        ++j;
      }
    }
    return j + cnt == word.size();
  }
};
