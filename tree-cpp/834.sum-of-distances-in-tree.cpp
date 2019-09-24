/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 *
 * https://leetcode.com/problems/sum-of-distances-in-tree/description/
 *
 * algorithms
 * Hard (40.81%)
 * Likes:    523
 * Dislikes: 26
 * Total Accepted:    9.3K
 * Total Submissions: 22.9K
 * Testcase Example:  '6\n[[0,1],[0,2],[2,3],[2,4],[2,5]]'
 *
 * An undirected, connected tree with N nodes labelled 0...N-1 and N-1 edges
 * are given.
 * 
 * The ith edge connects nodes edges[i][0] and edges[i][1] together.
 * 
 * Return a list ans, where ans[i] is the sum of the distances between node i
 * and all other nodes.
 * 
 * Example 1:
 * 
 * 
 * Input: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
 * Output: [8,12,6,10,10,10]
 * Explanation: 
 * Here is a diagram of the given tree:
 * ⁠ 0
 * ⁠/ \
 * 1   2
 * ⁠  /|\
 * ⁠ 3 4 5
 * We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
 * equals 1 + 1 + 2 + 2 + 2 = 8.  Hence, answer[0] = 8, and so on.
 * 
 * 
 * Note: 1 <= N <= 10000
 * 
 */
class Solution
{
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(N);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // use any node as root, view as a tree
        vector<int> cnt(N);
        vector<int> res(N);
        vector<bool> visited(N);
        int root = 0;
        count(g, cnt, res, visited, 0, 0, root);
        getDistance(g, cnt, res, visited, 0);

        return res;
    }

    int count(vector<vector<int>> &g, vector<int> &cnt, vector<int> &res, vector<bool> &visited, int pos, int distance, int root)
    {
        res[root] += distance;
        visited[pos] = true;
        cnt[pos] += 1;
        for (auto &i : g[pos])
        {
            if (visited[i])
                continue;
            cnt[pos] += count(g, cnt, res, visited, i, distance + 1, root);
        }
        visited[pos] = false;
        return cnt[pos];
    }

    void getDistance(vector<vector<int>> &g, vector<int> &cnt, vector<int> &res, vector<bool> &visited, int pos)
    {
        int n = cnt.size();
        visited[pos] = true;
        for (auto &v : g[pos])
        {
            if (visited[v])
                continue;
            res[v] = res[pos] - 2 * cnt[v] + n;
            getDistance(g, cnt, res, visited, v);
        }
    }
};
