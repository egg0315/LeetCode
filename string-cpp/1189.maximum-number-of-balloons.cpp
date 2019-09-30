/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 *
 * https://leetcode.com/problems/maximum-number-of-balloons/description/
 *
 * algorithms
 * Easy (62.85%)
 * Likes:    53
 * Dislikes: 11
 * Total Accepted:    9.4K
 * Total Submissions: 14.9K
 * Testcase Example:  '"nlaebolko"'
 *
 * Given a string text, you want to use the characters of text to form as many
 * instances of the word "balloon" as possible.
 * 
 * You can use each character in text at most once. Return the maximum number
 * of instances that can be formed.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: text = "nlaebolko"
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: text = "loonbalxballpoon"
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: text = "leetcode"
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= text.length <= 10^4
 * text consists of lower case English letters only.
 * 
 */
class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> count;
        for (auto &c : text)
            count[c]++;
        int ans = INT_MAX;
        ans = min(ans, count['b']);
        ans = min(ans, count['a']);
        ans = min(ans, count['n']);
        ans = min(ans, count['o'] / 2);
        ans = min(ans, count['l'] / 2);
        return ans;
    }
};
