/*
 * @lc app=leetcode id=1201 lang=cpp
 *
 * [1201] Ugly Number III
 *
 * https://leetcode.com/problems/ugly-number-iii/description/
 *
 * algorithms
 * Medium (20.10%)
 * Likes:    36
 * Dislikes: 73
 * Total Accepted:    1.8K
 * Total Submissions: 8.8K
 * Testcase Example:  '3\n2\n3\n5'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive integers which are divisible by a or b or c.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, a = 2, b = 3, c = 5
 * Output: 4
 * Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, a = 2, b = 3, c = 4
 * Output: 6
 * Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 12... The 4th is 6.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 5, a = 2, b = 11, c = 13
 * Output: 10
 * Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is
 * 10.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
 * Output: 1999999984
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n, a, b, c <= 10^9
 * 1 <= a * b * c <= 10^18
 * It's guaranteed that the result will be in range [1, 2 * 10^9]
 * 
 * 
 */
class Solution
{
public:
    int nthUglyNumber(int n, int A, int B, int C)
    {
        long a = A, b = B, c = C;
        long ab = a * b / __gcd(a, b);
        long bc = c * b / __gcd(b, c);
        long ac = a * c / __gcd(a, c);
        long abc = a * bc / __gcd(a, bc);

        long low = 1, high = 2e9;
        while (low < high)
        {
            long mid = (low + high) / 2;
            int cnt = mid / a + mid / b + mid / c - mid / ac - mid / bc - mid / ab + mid / abc;
            if (cnt < n)
            {
                low = mid + 1;
            }
            else
                high = mid;
        }
        return low;
    }
};
