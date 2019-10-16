/*
 * @lc app=leetcode id=288 lang=cpp
 *
 * [288] Unique Word Abbreviation
 *
 * https://leetcode.com/problems/unique-word-abbreviation/description/
 *
 * algorithms
 * Medium (20.51%)
 * Likes:    75
 * Dislikes: 995
 * Total Accepted:    44.4K
 * Total Submissions: 216K
 * Testcase Example:
 * '["ValidWordAbbr","isUnique","isUnique","isUnique","isUnique"]\n[[["deer","door","cake","card"]],["dear"],["cart"],["cane"],["make"]]'
 *
 * An abbreviation of a word follows the form <first letter><number><last
 * letter>. Below are some examples of word abbreviations:
 *
 *
 * a) it                      --> it    (no abbreviation)
 *
 * ⁠    1
 * ⁠    ↓
 * b) d|o|g                   --> d1g
 *
 * ⁠             1    1  1
 * ⁠    1---5----0----5--8
 * ⁠    ↓   ↓    ↓    ↓  ↓
 * c) i|nternationalizatio|n  --> i18n
 *
 * ⁠             1
 * ⁠    1---5----0
 * ↓   ↓    ↓
 * d) l|ocalizatio|n          --> l10n
 *
 *
 * Assume you have a dictionary and given a word, find whether its abbreviation
 * is unique in the dictionary. A word's abbreviation is unique if no other
 * word from the dictionary has the same abbreviation.
 *
 * Example:
 *
 *
 * Given dictionary = [ "deer", "door", "cake", "card" ]
 *
 * isUnique("dear") -> false
 * isUnique("cart") -> true
 * isUnique("cane") -> false
 * isUnique("make") -> true
 *
 *
 */
class ValidWordAbbr {
public:
  unordered_map<string, vector<string>> mp;
  unordered_set<string> words;
  ValidWordAbbr(vector<string> &dictionary) {
    for (auto &s : dictionary) {
      if (words.find(s) == words.end()) {
        words.insert(s);
        mp[abbr(s)].push_back(s);
      }
    }
  }

  bool isUnique(string s) {
    return words.find(s) == words.end() ? mp[abbr(s)].size() == 0
                                        : mp[abbr(s)].size() == 1;
  }

  string abbr(const string &s) {
    if (s.size() <= 2)
      return s;
    int n = s.size();
    return s[0] + to_string(n - 2) + s.back();
  }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
