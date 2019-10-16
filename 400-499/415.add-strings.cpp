/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 * tag : string, big number
 */
class Solution {
public:
  string addStrings(string a, string b, int carry = 0) {
    int i = a.size() - 1, j = b.size() - 1;
    string res;
    while (i >= 0 || j >= 0 || carry) {
      int aa = i >= 0 ? a[i--] - '0' : 0;
      int bb = j >= 0 ? b[j--] - '0' : 0;
      int sum = carry + aa + bb;
      res += sum % 10 + '0';
      carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
