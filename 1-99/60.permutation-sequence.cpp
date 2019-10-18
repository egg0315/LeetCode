/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (34.15%)
 * Likes:    1014
 * Dislikes: 268
 * Total Accepted:    153.3K
 * Total Submissions: 446.4K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        // convert to zero base
        --k;
        string res;
        bool used[n + 1] = {};
        for (int i = 1; i <= n; ++i)
        {
            int sz = factorial(n - i);
            int index = k / sz;
            k -= index * sz;
            // find index-th smallest unused number
            for (int j = 1; j <= n; ++j)
            {
                if (!used[j])
                {
                    if (!index)
                    {
                        used[j] = true;
                        res += j + '0';
                    }
                    --index;
                }
            }
        }
        return res;
    }
    int factorial(int n)
    {
        if (n == 1 || n == 0)
            return 1;
        return n * factorial(n - 1);
    }
};
// @lc code=end
