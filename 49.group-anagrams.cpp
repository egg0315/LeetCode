/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (50.18%)
 * Likes:    2158
 * Dislikes: 134
 * Total Accepted:    421.8K
 * Total Submissions: 839.4K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        // using count[26] will improve speed, but essentially the same algo
        unordered_map<string, vector<string>> mapp;

        for (auto s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            mapp[key].push_back(s);
        }
        for (auto p : mapp)
        {
            res.push_back(p.second);
        }
        return res;
    }
};
// @lc code=end
