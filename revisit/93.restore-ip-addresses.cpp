/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */
class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    for (int a = 1; a <= 3; ++a) {
      for (int b = 1; b <= 3; ++b) {
        for (int c = 1; c <= 3; ++c) {
          for (int d = 1; d <= 3; ++d) {
            if (a + b + c + d == s.size()) {
              int A = stoi(s.substr(0, a));
              int B = stoi(s.substr(a, b));
              int C = stoi(s.substr(a + b, c));
              int D = stoi(s.substr(a + b + c, d));
              if (A < 256 && B < 256 && C < 256 && D < 256) {
                string ip = getIP(A, B, C, D);
                if (ip.size() == s.size() + 3)
                  res.push_back(ip);
              }
            }
          }
        }
      }
    }
    return res;
  }

  string getIP(int A, int B, int C, int D) {
    return to_string(A) + '.' + to_string(B) + '.' + to_string(C) + '.' +
           to_string(D);
  }
};
