/*
 * @lc app=leetcode id=639 lang=cpp
 *
 * [639] Decode Ways II
 *
 * https://leetcode.com/problems/decode-ways-ii/description/
 *
 * algorithms
 * Hard (25.60%)
 * Likes:    299
 * Dislikes: 403
 * Total Accepted:    24.2K
 * Total Submissions: 94.5K
 * Testcase Example:  '"*"'
 *
 * 
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping way:
 * 
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 
 * Beyond that, now the encoded string can also contain the character '*',
 * which can be treated as one of the numbers from 1 to 9.
 * 
 * 
 * 
 * 
 * Given the encoded message containing digits and the character '*', return
 * the total number of ways to decode it.
 * 
 * 
 * 
 * Also, since the answer may be very large, you should return the output mod
 * 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * Input: "*"
 * Output: 9
 * Explanation: The encoded message can be decoded to the string: "A", "B",
 * "C", "D", "E", "F", "G", "H", "I".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "1*"
 * Output: 9 + 9 = 18
 * 
 * 
 * 
 * Note:
 * 
 * The length of the input string will fit in range [1, 10^5].
 * The input string will only contain the character '*' and digits '0' - '9'.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    const long MOD = 1e9 + 7;
    int numDecodings(string s)
    {
        int n = s.size();
        long dp[n + 1] = {};
        dp[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            char c = s[i];
            if (c == '0')
            {
                if (i == 0)
                    return 0;
                // zero will limit prev char
                else if (s[i - 1] == '*')
                {
                    dp[i + 1] = (dp[i - 1] * 2) % MOD;
                }
                else if (s[i - 1] == '1' || s[i - 1] == '2')
                {
                    dp[i + 1] = dp[i - 1] % MOD;
                }
                else
                    return 0;
            }
            else
            {
                if (c == '*')
                {
                    if (i == 0)
                    {
                        dp[i + 1] = dp[i] * 9;
                    }
                    else if (s[i - 1] == '1')
                    {
                        dp[i + 1] = (dp[i] + dp[i - 1]) * 9;
                    }
                    else if (s[i - 1] == '2')
                    {
                        dp[i + 1] = dp[i] * 9 + dp[i - 1] * 6;
                    }
                    // "**" [11,26] except 20
                    else if (s[i - 1] == '*')
                    {
                        dp[i + 1] = dp[i] * 9 + dp[i - 1] * 15;
                    }
                    else
                    {
                        dp[i + 1] = dp[i] * 9;
                    }
                }
                else if (i && s[i - 1] == '*')
                {
                    if (c >= '1' && c <= '6')
                    {
                        dp[i + 1] = dp[i] + 2 * dp[i - 1];
                    }
                    else
                    {
                        dp[i + 1] = dp[i] + dp[i - 1];
                    }
                }
                else if (i && s[i - 1] == '1')
                {
                    dp[i + 1] = (dp[i] + dp[i - 1]);
                }
                else if (i && s[i - 1] == '2' && (c >= '1' && c <= '6'))
                {
                    dp[i + 1] = (dp[i] + dp[i - 1]);
                }
                else
                {
                    dp[i + 1] = dp[i];
                }
            }
            dp[i + 1] %= MOD;
        }

        return dp[n];
    }
};
// @lc code=end
