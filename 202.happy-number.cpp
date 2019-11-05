/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (47.07%)
 * Likes:    1130
 * Dislikes: 288
 * Total Accepted:    284.4K
 * Total Submissions: 602.7K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 */

// @lc code=start
class Solution
{
public:
    unordered_set<int> seen;
    bool isHappy(int n)
    {
        if (n == 1)
            return true;
        int slow = n, fast = n;
        while (1)
        {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
            if (slow == 1 || fast == 1)
                return true;
            if (slow == fast)
                return false;
        }
        // useless
        return false;
    }

    int digitSquareSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
};
// @lc code=end
