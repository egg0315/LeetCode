/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (31.92%)
 * Likes:    1064
 * Dislikes: 61
 * Total Accepted:    133.7K
 * Total Submissions: 413.8K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * 
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or .. A . means it can represent any one
 * letter.
 * 
 * Example:
 * 
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * 
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 * 
 */

// @lc code=start
class TrieNode
{
public:
    bool isWord;
    TrieNode *children[26];
    TrieNode()
    {
        isWord = false;
        for (auto &ch : children)
        {
            ch = nullptr;
        }
    }
};

class WordDictionary
{
public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        auto p = root;
        for (auto &c : word)
        {
            if (!p->children[c - 'a'])
            {
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
        }
        p->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return helper(word, 0, root);
    }

    bool helper(string &word, int index, TrieNode *p)
    {
        if (p == nullptr)
            return false;
        if (index == word.size())
            return p->isWord;
        if (word[index] == '.')
        {
            for (auto &ch : p->children)
            {
                if (helper(word, index + 1, ch))
                    return true;
            }
            return false;
        }
        return helper(word, index + 1, p->children[word[index] - 'a']);
    }

private:
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
