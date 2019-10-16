/*
 * @lc app=leetcode id=1178 lang=cpp
 *
 * [1178] Number of Valid Words for Each Puzzle
 *
 * https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/description/
 *
 * algorithms
 * Hard (34.29%)
 * Likes:    103
 * Dislikes: 8
 * Total Accepted:    3.2K
 * Total Submissions: 9.1K
 * Testcase Example:  '["aaaa","asas","able","ability","actt","actor","access"]\n["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]'
 *
 * With respect to a given puzzle string, a word is valid if both the following
 * conditions are satisfied:
 * 
 * word contains the first letter of puzzle.
 * For each letter in word, that letter is in puzzle.
 * For example, if the puzzle is "abcdefg", then valid words are "faced",
 * "cabbage", and "baggage"; while invalid words are "beefed" (doesn't include
 * "a") and "based" (includes "s" which isn't in the puzzle).
 * 
 * Return an array answer, where answer[i] is the number of words in the given
 * word list words that are valid with respect to the puzzle puzzles[i].
 * 
 * Example :
 * 
 * 
 * Input: 
 * words = ["aaaa","asas","able","ability","actt","actor","access"], 
 * puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
 * Output: [1,1,3,2,4,0]
 * Explanation:
 * 1 valid word for "aboveyz" : "aaaa" 
 * 1 valid word for "abrodyz" : "aaaa"
 * 3 valid words for "abslute" : "aaaa", "asas", "able"
 * 2 valid words for "absoryz" : "aaaa", "asas"
 * 4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
 * There're no valid words for "gaswxyz" cause none of the words in the list
 * contains letter 'g'.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 10^5
 * 4 <= words[i].length <= 50
 * 1 <= puzzles.length <= 10^4
 * puzzles[i].length == 7
 * words[i][j], puzzles[i][j] are English lowercase letters.
 * Each puzzles[i] doesn't contain repeated characters.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
    {
        int n = words.size();
        int m = puzzles.size();
        unordered_map<int, int> count;
        for (auto &s : words)
        {
            int mask = 0;
            for (auto &c : s)
            {
                mask |= 1 << (c - 'a');
            }
            count[mask]++;
        }

        vector<int> res(m);
        int mask, sub;
        bool valid;
        for (int j = 0; j < m; ++j)
        {
            const auto &p = puzzles[j];
            int len = p.size();

            for (int k = 0; k < (1 << len - 1); ++k)
            {
                // this make sure first letter of puzzle is included
                sub = 1 << (p[0] - 'a');
                for (int i = 0; i < len - 1; ++i)
                {
                    if (k & (1 << i))
                    {
                        sub |= 1 << (p[i + 1] - 'a');
                    }
                }
                res[j] += count[sub];
            }
        }
        return res;
    }
};
// @lc code=end
