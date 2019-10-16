/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 *
 * https://leetcode.com/problems/strange-printer/description/
 *
 * algorithms
 * Hard (37.74%)
 * Likes:    294
 * Dislikes: 38
 * Total Accepted:    10.5K
 * Total Submissions: 27.9K
 * Testcase Example:  '"aaabbb"'
 *
 * 
 * There is a strange printer with the following two special requirements:
 * 
 * 
 * The printer can only print a sequence of the same character each time.
 * At each turn, the printer can print new characters starting from and ending
 * at any places, and will cover the original existing characters.
 * 
 * 
 * 
 * 
 * 
 * Given a string consists of lower English letters only, your job is to count
 * the minimum number of turns the printer needed in order to print it.
 * 
 * 
 * Example 1:
 * 
 * Input: "aaabbb"
 * Output: 2
 * Explanation: Print "aaa" first and then print "bbb".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "aba"
 * Output: 2
 * Explanation: Print "aaa" first and then print "b" from the second place of
 * the string, which will cover the existing character 'a'.
 * 
 * 
 * 
 * Hint: Length of the given string will not exceed 100.
 */
class Solution
{
public:
    int strangePrinter(string s)
    {
        if (s.size() == 0)
            return 0;
        int n = s.size();
        int dp[n][n] = {};
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            for (int len = 1; len + i < n; ++len)
            {
                int j = i + len;
                if (len == 1)
                {
                    dp[i][j] = s[i] == s[j] ? 1 : 2;
                }
                else
                {
                    dp[i][j] = INT_MAX;
                    for (int k = i; k + 1 <= j; ++k)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                    if (s[i] == s[j])
                    {
                        dp[i][j]--;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
