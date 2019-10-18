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
        vector<int> factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
        string s = "123456789";
        s = s.substr(0, n);
        string res;
        int i = n - 1;
        while (i >= 0)
        {
            int index = (k - 1) / factorial[i];
            k -= index * factorial[i];
            res += s[index];
            cout << s[index];
            while (index + 1 < n)
            {
                s[index] = s[index + 1];
                index++;
            }
            i--;
        }
        return res;
    }
};
// @lc code=end