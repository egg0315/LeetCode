/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (45.01%)
 * Likes:    1632
 * Dislikes: 62
 * Total Accepted:    108.1K
 * Total Submissions: 240.2K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &p)
    {
        int n = p.size();
        if (n < 2)
            return 0;
        int sold[n + 1] = {};
        int hold[n + 1] = {};
        hold[0] = -p[0];
        for (int i = 1; i <= n; ++i)
        {
            hold[i] = i == 1 ? hold[i - 1] : max(hold[i - 1], sold[i - 2] - p[i - 1]);
            sold[i] = max(sold[i - 1], hold[i - 1] + p[i - 1]);
        }
        return sold[n];
    }
};
// @lc code=end
