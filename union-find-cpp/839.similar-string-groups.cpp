/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [839] Similar String Groups
 *
 * https://leetcode.com/problems/similar-string-groups/description/
 *
 * algorithms
 * Hard (35.63%)
 * Likes:    189
 * Dislikes: 64
 * Total Accepted:    11K
 * Total Submissions: 30.9K
 * Testcase Example:  '["tars","rats","arts","star"]'
 *
 * Two strings X and Y are similar if we can swap two letters (in different
 * positions) of X, so that it equals Y.
 * 
 * For example, "tars" and "rats" are similar (swapping at positions 0 and 2),
 * and "rats" and "arts" are similar, but "star" is not similar to "tars",
 * "rats", or "arts".
 * 
 * Together, these form two connected groups by similarity: {"tars", "rats",
 * "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group
 * even though they are not similar.  Formally, each group is such that a word
 * is in the group if and only if it is similar to at least one other word in
 * the group.
 * 
 * We are given a list A of strings.  Every string in A is an anagram of every
 * other string in A.  How many groups are there?
 * 
 * Example 1:
 * 
 * 
 * Input: ["tars","rats","arts","star"]
 * Output: 2
 * 
 * Note:
 * 
 * 
 * A.length <= 2000
 * A[i].length <= 1000
 * A.length * A[i].length <= 20000
 * All words in A consist of lowercase letters only.
 * All words in A have the same length and are anagrams of each other.
 * The judging time limit has been increased for this question.
 * 
 * 
 */
class Solution
{
public:
    int numSimilarGroups(vector<string> &A)
    {
        unordered_set<string> B(A.begin(), A.end());
        vector<string> strs(B.begin(), B.end());
        int n = strs.size();
        disjoint_set ds(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (similar(strs[i], strs[j]))
                {
                    ds.join(i, j);
                }
            }
        }
        return ds.component();
    }

    bool similar(string &a, string &b)
    {
        int cnt = 0;

        for (int k = 0; k < a.size(); k++)
        {
            if (a[k] != b[k])
                cnt++;
            if (cnt > 2)
                return false;
        }
        return cnt == 2;
    }

    class disjoint_set
    {
    public:
        disjoint_set(int n)
        {
            make_set(n);
        }

        void make_set(int n)
        {
            id.resize(n);
            iota(begin(id), end(id), 0);
            size = n;
        }

        // return true if p, q already in a set, means redundent connection
        bool join(int p, int q)
        {
            int pid = find(p);
            int qid = find(q);
            if (pid == qid)
                return true;
            id[pid] = qid;
            size--;
            return false;
        }

        int find(int p)
        {
            int r = p;
            while (r != id[r])
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

        int component()
        {
            return size;
        }

    private:
        vector<int> id;
        int size;
    };
};
