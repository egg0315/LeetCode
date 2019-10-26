/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (37.76%)
 * Likes:    1156
 * Dislikes: 74
 * Total Accepted:    119.4K
 * Total Submissions: 316K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 * 
 * Example:
 * 
 * 
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * Note:  
 * 
 * 
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 * 
 */

// @lc code=start
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n == 1)
            return 1;
        int t2 = 0, t3 = 0, t5 = 0;
        vector<int> k(n);
        k[0] = 1;
        for (int i = 1; i < n; i++)
        {
            k[i] = min(k[t2] * 2, min(k[t3] * 3, k[t5] * 5));
            if (k[i] == k[t2] * 2)
                t2++;
            if (k[i] == k[t3] * 3)
                t3++;
            if (k[i] == k[t5] * 5)
                t5++;
        }
        return k[n - 1];
    }
};
// @lc code=end
