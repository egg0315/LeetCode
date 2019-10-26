/*
 * @lc app=leetcode id=267 lang=cpp
 *
 * [267] Palindrome Permutation II
 *
 * https://leetcode.com/problems/palindrome-permutation-ii/description/
 *
 * algorithms
 * Medium (34.62%)
 * Likes:    304
 * Dislikes: 41
 * Total Accepted:    30K
 * Total Submissions: 86.7K
 * Testcase Example:  '"aabb"'
 *
 * Given a string s, return all the palindromic permutations (without
 * duplicates) of it. Return an empty list if no palindromic permutation could
 * be form.
 * 
 * Example 1:
 * 
 * 
 * Input: "aabb"
 * Output: ["abba", "baab"]
 * 
 * Example 2:
 * 
 * 
 * Input: "abc"
 * Output: []
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<string> generatePalindromes(string s)
    {
        int count[128] = {};
        for (auto &c : s)
        {
            count[c]++;
        }
        int odd = 0;
        char cc;
        for (int i = 0; i < 128; ++i)
        {
            int c = count[i];
            odd += (c % 2);
            if (c % 2)
            {
                cc = i;
            }
        }
        vector<string> res;
        if (odd > 1)
            return res;
        bool single = odd;
        string half;
        for (auto &i : count)
            i /= 2;
        for (int i = 0; i < 128; ++i)
        {
            if (count[i])
            {
                char c = i;
                half.append(count[i], c);
            }
        }
        do
        {
            string second_half = half;
            reverse(begin(second_half), end(second_half));
            if (single)
            {
                res.push_back(half + cc + second_half);
            }
            else
            {
                res.push_back(half + second_half);
            }
        } while (next_permutation(begin(half), end(half)));

        return res;
    }
};
// @lc code=end
