/*
 * @lc app=leetcode id=517 lang=cpp
 *
 * [517] Super Washing Machines
 *
 * https://leetcode.com/problems/super-washing-machines/description/
 *
 * algorithms
 * Hard (37.04%)
 * Likes:    224
 * Dislikes: 119
 * Total Accepted:    13.6K
 * Total Submissions: 36.6K
 * Testcase Example:  '[1,0,5]'
 *
 * You have n super washing machines on a line. Initially, each washing machine
 * has some dresses or is empty. 
 * 
 * 
 * For each move, you could choose any m (1 ≤ m ≤ n) washing machines, and pass
 * one dress of each washing machine to one of its adjacent washing machines
 * at the same time .  
 * 
 * Given an integer array representing the number of dresses in each washing
 * machine from left to right on the line, you should find the minimum number
 * of moves to make all the washing machines have the same number of dresses.
 * If it is not possible to do it, return -1.
 * 
 * Example1
 * 
 * Input: [1,0,5]
 * 
 * Output: 3
 * 
 * Explanation: 
 * 1st move:    1     0     1     1     4
 * 2nd move:    1     2     1     3    
 * 3rd move:    2     1     2     2     2   
 * 
 * 
 * Example2
 * 
 * Input: [0,3,0]
 * 
 * Output: 2
 * 
 * Explanation: 
 * 1st move:    0     1     2     0    
 * 2nd move:    1     2 --> 0    =>    1     1     1     
 * 
 * 
 * Example3
 * 
 * Input: [0,2,0]
 * 
 * Output: -1
 * 
 * Explanation: 
 * It's impossible to make all the three washing machines have the same number
 * of dresses. 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The range of n is [1, 10000].
 * The range of dresses number in a super washing machine is [0, 1e5].
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int findMinMoves(vector<int> &a)
    {
        int n = a.size();
        int total = accumulate(a.begin(), a.end(), 0);
        if (total % n)
            return -1;
        int average = total / n;
        int res = 0, cur = 0;
        for (auto i : a)
        {
            cur += i - average;
            res = max(res, max(i - average, abs(cur)));
        }
        return res;
    }
};
// @lc code=end
