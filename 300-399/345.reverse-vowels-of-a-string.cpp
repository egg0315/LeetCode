/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 * tag : string
 */
class Solution {
public:
  string reverseVowels(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      while (i < j && !isVowel(s[i])) {
        ++i;
      }
      while (i < j && !isVowel(s[j])) {
        --j;
      }
      if (i != j) {
        swap(s[i++], s[j--]);
      }
    }
    return s;
  }

  bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};
