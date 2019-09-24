/*
 * @lc app=leetcode id=809 lang=cpp
 *
 * [809] Expressive Words
 *
 * https://leetcode.com/problems/expressive-words/description/
 *
 * algorithms
 * Medium (44.85%)
 * Likes:    131
 * Dislikes: 412
 * Total Accepted:    18K
 * Total Submissions: 40.1K
 * Testcase Example:  '"heeellooo"\n["hello", "hi", "helo"]'
 *
 * Sometimes people repeat letters to represent extra feeling, such as "hello"
 * -> "heeellooo", "hi" -> "hiiii".  In these strings like "heeellooo", we have
 * groups of adjacent letters that are all the same:  "h", "eee", "ll", "ooo".
 * 
 * For some given string S, a query word is stretchy if it can be made to be
 * equal to S by any number of applications of the following extension
 * operation: choose a group consisting of characters c, and add some number of
 * characters c to the group so that the size of the group is 3 or more.
 * 
 * For example, starting with "hello", we could do an extension on the group
 * "o" to get "hellooo", but we cannot get "helloo" since the group "oo" has
 * size less than 3.  Also, we could do another extension like "ll" -> "lllll"
 * to get "helllllooo".  If S = "helllllooo", then the query word "hello" would
 * be stretchy because of these two extension operations: query = "hello" ->
 * "hellooo" -> "helllllooo" = S.
 * 
 * Given a list of query words, return the number of words that are
 * stretchy. 
 * 
 * 
 * 
 * 
 * Example:
 * Input: 
 * S = "heeellooo"
 * words = ["hello", "hi", "helo"]
 * Output: 1
 * Explanation: 
 * We can extend "e" and "o" in the word "hello" to get "heeellooo".
 * We can't extend "helo" to get "heeellooo" because the group "ll" is not size
 * 3 or more.
 * 
 * 
 * 
 * 
 * Notes: 
 * 
 * 
 * 0 <= len(S) <= 100.
 * 0 <= len(words) <= 100.
 * 0 <= len(words[i]) <= 100.
 * S and all words in words consist only of lowercase letters
 * 
 * 
 * 
 * 
 */
class Solution
{
public:
    int expressiveWords(string s, vector<string> &words)
    {
        int res = 0;
        for (auto &w : words)
            res += sketchy(s, w);
        return res;
    }

    bool sketchy(string s, string w)
    {
        int n = s.size(), m = w.size(), j = 0;
        for (int i = 0; i < n; i++)
            if (j < m && s[i] == w[j])
                j++;
            else if (i > 1 && s[i - 2] == s[i - 1] && s[i - 1] == s[i])
                ; // matched two letters prev, prev, cur
            else if (i > 0 && i < n - 1 && s[i - 1] == s[i] && s[i] == s[i + 1])
                ; // matched one letter, prev, cur, next
            else
                return false;
        return j == m;
    }
};
