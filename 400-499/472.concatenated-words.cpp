/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 *
 * https://leetcode.com/problems/concatenated-words/description/
 *
 * algorithms
 * Hard (36.81%)
 * Likes:    324
 * Dislikes: 73
 * Total Accepted:    27.8K
 * Total Submissions: 75.6K
 * Testcase Example:  '["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]'
 *
 * Given a list of words (without duplicates), please write a program that
 * returns all concatenated words in the given list of words.
 * A concatenated word is defined as a string that is comprised entirely of at
 * least two shorter words in the given array.
 * 
 * Example:
 * 
 * Input:
 * ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
 * 
 * Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
 * 
 * Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
 * "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; "ratcatdogcat"
 * can be concatenated by "rat", "cat", "dog" and "cat".
 * 
 * 
 * 
 * Note:
 * 
 * The number of elements of the given array will not exceed 10,000 
 * The length sum of elements in the given array will not exceed 600,000. 
 * All the input string will only include lower case letters.
 * The returned elements order does not matter. 
 * 
 * 
 */
class TrieNode
{
public:
    TrieNode *child[26];
    bool isWord;

    TrieNode()
    {
        isWord = false;
        for (auto &ch : child)
            ch = NULL;
    }
};

class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        root = new TrieNode();
        for (auto &s : words)
            insert(s);
        vector<string> res;

        for (auto &w : words)
        {
            if (search(w, 0, 0))
                res.push_back(w);
        }
        return res;
    }

    void insert(string &word)
    {
        auto p = root;
        for (auto &c : word)
        {
            if (p->child[c - 'a'] == NULL)
            {
                p->child[c - 'a'] = new TrieNode();
            }
            p = p->child[c - 'a'];
        }
        p->isWord = true;
    }

    bool search(string &s, int index, int count)
    {
        if (index == s.size())
        {
            return count > 1;
        }
        auto p = root;
        for (int i = index; i < s.size(); ++i)
        {
            if (p->child[s[i] - 'a'] == NULL)
                return false;
            p = p->child[s[i] - 'a'];
            if (p->isWord)
            {
                if (search(s, i + 1, count + 1))
                    return true;
            }
        }
        return false;
    }

private:
    TrieNode *root;
};
// word break solution
// class Solution
// {
// public:
//     unordered_set<string> dict;
//     vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
//     {
//         for (auto &s : words)
//             dict.insert(s);
//         vector<string> res;
//         for (auto &s : words)
//         {
//             if (s.empty())
//                 continue;
//             if (wordBreak(s))
//                 res.push_back(s);
//         }
//         return res;
//     }

//     bool wordBreak(string &s)
//     {
//         int n = s.size();
//         bool dp[n + 1] = {};
//         dp[0] = true;
//         for (int i = 1; i <= n; ++i)
//         {
//             for (int j = i; j >= 0; --j)
//             {
//                 if (i == n && j == 0)
//                     continue;
//                 // optimization from 528ms to 329ms to 240ms
//                 if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
//                 {
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//         return dp[n];
//     }
// };
