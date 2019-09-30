/*
 * @lc app=leetcode id=479 lang=cpp
 *
 * [479] Largest Palindrome Product
 *
 * https://leetcode.com/problems/largest-palindrome-product/description/
 *
 * algorithms
 * Hard (27.83%)
 * Likes:    74
 * Dislikes: 1246
 * Total Accepted:    15.4K
 * Total Submissions: 55.4K
 * Testcase Example:  '1'
 *
 * Find the largest palindrome made from the product of two n-digit numbers.
 * 
 * Since the result could be very large, you should return the largest
 * palindrome mod 1337.
 * 
 * 
 * 
 * Example:
 * 
 * Input: 2
 * 
 * Output: 987
 * 
 * Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
 * 
 * 
 * 
 * Note:
 * 
 * The range of n is [1,8].
 * 
 */

// @lc code=start
class Solution
{
public:
    const long MOD = 1337;
    int largestPalindrome(int n)
    {
        if (n == 1)
            return 9;
        // result length could be 2*n, 2*n-1
        // numerate all possible palindromes
        int hi = pow(10, n) - 1;
        int lo = pow(10, n - 1);
        // even palindrome
        for (int i = hi; i >= lo; --i)
        {
            long tmp = buildEven(i);
            for (long k = hi; k * k >= tmp; --k)
            {
                if (tmp % k == 0)
                {
                    return tmp % MOD;
                }
            }
        }
        // odd palindrome
        // example n == 2: from 999 to 101
        hi /= 10;
        for (long i = hi; i >= lo; --i)
        {
            long tmp = buildOdd(i);
            for (long k = lo; k * k <= 10 * hi; ++k)
            {
                if (tmp % k == 0)
                    return tmp % MOD;
            }
        }
        return -1;
    }

    long buildEven(int num)
    {
        string s = to_string(num);
        reverse(s.begin(), s.end());
        s = to_string(num) + s;
        return stoll(s);
    }

    long buildOdd(int num)
    {
        string rev = to_string(num);
        rev.pop_back();
        reverse(rev.begin(), rev.end());
        return stoll(to_string(num) + rev);
    }
};
// @lc code=end
