/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 * tag : string, big integer, divide and conquor
 */
class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";
    int n = num1.size(), m = num2.size();
    vector<int> res(m + n + 1);
    for (int i = m - 1; i >= 0; --i) {
      // length n + 1
      vector<int> tmp = helper(num1, num2[i]);
      // add tmp to res vector
      for (int j = n; j >= 0; --j) {
        res[j + i + 1] += tmp[j];
      }
    }
    int carry = 0;
    for (int i = m + n; i >= 0; --i) {
      int sum = (res[i] + carry);
      carry = sum / 10;
      res[i] = sum % 10;
    }
    string s;
    for (auto i : res) {
      s += i + '0';
    }
    int i = 0;
    while (i < s.size() && s[i] == '0')
      ++i;
    return s.substr(i);
  }

  vector<int> helper(const string &num, char c) {
    int n = num.size();
    vector<int> res(n + 1);
    int carry = 0;
    int d = c - '0';
    for (int i = n - 1; i >= 0; --i) {
      int t = (num[i] - '0') * d + carry;
      res[i + 1] = t % 10;
      carry = t / 10;
    }
    res[0] = carry;
    return res;
  }
};
