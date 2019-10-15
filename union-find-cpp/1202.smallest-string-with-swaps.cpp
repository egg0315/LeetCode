/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 *
 * https://leetcode.com/problems/smallest-string-with-swaps/description/
 *
 * algorithms
 * Medium (37.62%)
 * Likes:    121
 * Dislikes: 4
 * Total Accepted:    3.1K
 * Total Submissions: 8.3K
 * Testcase Example:  '"dcab"\n[[0,3],[1,2]]'
 *
 * You are given a string s, and an array of pairs of indices in the string
 * pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
 * 
 * You can swap the characters at any pair of indices in the given pairs any
 * number of times.
 * 
 * Return the lexicographically smallest string that s can be changed to after
 * using the swaps.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "dcab", pairs = [[0,3],[1,2]]
 * Output: "bacd"
 * Explaination: 
 * Swap s[0] and s[3], s = "bcad"
 * Swap s[1] and s[2], s = "bacd"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
 * Output: "abcd"
 * Explaination: 
 * Swap s[0] and s[3], s = "bcad"
 * Swap s[0] and s[2], s = "acbd"
 * Swap s[1] and s[2], s = "abcd"
 * 
 * Example 3:
 * 
 * 
 * Input: s = "cba", pairs = [[0,1],[1,2]]
 * Output: "abc"
 * Explaination: 
 * Swap s[0] and s[1], s = "bca"
 * Swap s[1] and s[2], s = "bac"
 * Swap s[0] and s[1], s = "abc"
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * 0 <= pairs.length <= 10^5
 * 0 <= pairs[i][0], pairs[i][1] < s.length
 * s only contains lower case English letters.
 * 
 * 
 */
class Solution
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.size();
        disjoint_set ds;
        ds.init(n);
        vector<int> group(n);
        for (auto &p : pairs)
        {
            ds.join(p[0], p[1]);
        }
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < n; ++i)
        {
            group[i] = ds.find(i);
        }
        for (int i = 0; i < n; ++i)
        {
            g[group[i]].push_back(i);
        }
        string res = s;
        for (auto &[gid, v] : g)
        {
            string tmp;
            for (auto i : v)
                tmp += s[i];
            sort(tmp.begin(), tmp.end());
            int j = 0;
            for (auto i : v)
                res[i] = tmp[j++];
        }
        return res;
    }

    class disjoint_set
    {
    public:
        int size;
        vector<int> id;

        void init(int n)
        {
            size = n;
            id.resize(n);
            iota(begin(id), end(id), 0);
        }

        bool join(int p, int q)
        {
            int pid = find(p);
            int qid = find(q);
            if (pid == qid)
                return false;
            id[pid] = qid;
            --size;
            return true;
        }

        int find(int p)
        {
            int r = p;
            while (id[r] != r)
            {
                r = id[r];
            }
            int x = p;
            while (x != r)
            {
                int tmp = id[x];
                id[x] = r;
                x = tmp;
            }
            return r;
        }
    };
};
