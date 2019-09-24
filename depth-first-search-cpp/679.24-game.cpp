/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 *
 * https://leetcode.com/problems/24-game/description/
 *
 * algorithms
 * Hard (43.86%)
 * Likes:    448
 * Dislikes: 96
 * Total Accepted:    24.2K
 * Total Submissions: 55.1K
 * Testcase Example:  '[4,1,8,7]'
 *
 * 
 * You have 4 cards each containing a number from 1 to 9.  You need to judge
 * whether they could operated through *, /, +, -, (, ) to get the value of
 * 24.
 * 
 * 
 * Example 1:
 * 
 * Input: [4, 1, 8, 7]
 * Output: True
 * Explanation: (8-4) * (7-1) = 24
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2, 1, 2]
 * Output: False
 * 
 * 
 * 
 * Note:
 * 
 * The division operator / represents real division, not integer division.  For
 * example, 4 / (1 - 2/3) = 12.
 * Every operation done is between two numbers.  In particular, we cannot use -
 * as a unary operator.  For example, with [1, 1, 1, 1] as input, the
 * expression -1 - 1 - 1 - 1 is not allowed.
 * You cannot concatenate numbers together.  For example, if the input is [1,
 * 2, 1, 2], we cannot write this as 12 + 12.
 * 
 * 
 * 
 */
class Solution {
public:
    const double delta = 1e-6;
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do {
            if(cando(nums[0], nums[1], nums[2], nums[3]))
                return true;
        } while(next_permutation(begin(nums), end(nums)));
        return false;
    }
    
    bool cando(double a, double b, double c, double d) {
        return cando(a+b, c, d) || cando(a-b, c, d) || cando(a*b, c, d) || (b && cando(a/b, c, d)) ||
               cando(a, b+c, d) || cando(a, b-c, d) || cando(a, b*c, d) || (c && cando(a, b/c, d)) ||
               cando(a, b, c+d) || cando(a, b, c-d) || cando(a, b, c*d) || (d && cando(a, b, c/d));
    }
    
    bool cando(double a, double b, double c) {
        return cando(a+b, c) || cando(a-b, c) || cando(a*b, c) || (b && cando(a/b, c)) || 
               cando(a, b+c) || cando(a, b-c) || cando(a, b*c) || (c && cando(a, b/c));
    }
    
    bool cando(double a, double b) {
        return abs(a+b-24.0) < delta || abs(a*b-24.0) < delta || 
               abs(a-b-24.0) < delta || (b && (abs(a/b-24.0) < delta));
    }
};

