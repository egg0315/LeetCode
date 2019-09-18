/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */
class Solution {
public:
  unordered_map<long, int> seen;
  string fractionToDecimal(int num, int den) {
    long n = num, d = den;
    if (n == 0)
      return "0";
    string res;
    if (n > 0 ^ d > 0)
      res += '-';
    n = abs(n);
    d = abs(d);
    res += to_string(n / d);
    n -= (n / d) * d;
    if (n == 0)
      return res;
    res += '.';
    seen[n] = res.size();
    while (n) {
      n *= 10;
      res += to_string(n / d);
      n -= d * (n / d);
      if (seen.find(n) != seen.end()) {
        res.insert(seen[n], "(");
        res += ')';
        return res;
      }
      seen[n] = res.size();
    }
    return res;
  }
};
