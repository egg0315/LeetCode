/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (26.90%)
 * Likes:    951
 * Dislikes: 60
 * Total Accepted:    101.4K
 * Total Submissions: 375.5K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * Say you have an array for which the i-th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [2,4,1], k = 2
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4.
 * Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 =
 * 3.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n < 2)
            return 0;
        // as many as transaction
        if (k >= n / 2)
        {
            int res = 0;
            for (int i = 1; i < n; ++i)
                res += max(0, prices[i] - prices[i - 1]);
            return res;
        }
        vector<int> hold(k + 1, INT_MIN);
        vector<int> sold(k + 1, 0);
        for (auto &p : prices)
        {
            for (int i = 1; i <= k; ++i)
            {
                hold[i] = max(hold[i], sold[i - 1] - p);
                sold[i] = max(sold[i], hold[i] + p);
            }
        }
        return sold[k];
    }
};
// @lc code=end
