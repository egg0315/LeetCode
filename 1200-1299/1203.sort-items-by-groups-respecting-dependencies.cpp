/*
 * @lc app=leetcode id=1203 lang=cpp
 *
 * [1203] Sort Items by Groups Respecting Dependencies
 *
 * https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/
 *
 * algorithms
 * Hard (43.80%)
 * Likes:    45
 * Dislikes: 6
 * Total Accepted:    863
 * Total Submissions: 1.9K
 * Testcase Example:  '8\n2\n[-1,-1,1,0,0,1,0,-1]\n[[],[6],[5],[6],[3,6],[],[],[]]'
 *
 * There are n items each belonging to zero or one of m groups where group[i]
 * is the group that the i-th item belongs to and it's equal to -1 if the i-th
 * item belongs to no group. The items and the groups are zero indexed. A group
 * can have no item belonging to it.
 * 
 * Return a sorted list of the items such that:
 * 
 * 
 * The items that belong to the same group are next to each other in the sorted
 * list.
 * There are some relations between these items where beforeItems[i] is a list
 * containing all the items that should come before the i-th item in the sorted
 * array (to the left of the i-th item).
 * 
 * 
 * Return any solution if there is more than one solution and return an empty
 * list if there is no solution.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems =
 * [[],[6],[5],[6],[3,6],[],[],[]]
 * Output: [6,3,4,1,5,2,0,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems =
 * [[],[6],[5],[6],[3],[],[4],[]]
 * Output: []
 * Explanation: This is the same as example 1 except that 4 needs to be before
 * 6 in the sorted list.
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= m <= n <= 3*10^4
 * group.length == beforeItems.length == n
 * -1 <= group[i] <= m-1
 * 0 <= beforeItems[i].length <= n-1
 * 0 <= beforeItems[i][j] <= n-1
 * i != beforeItems[i][j]
 * beforeItems[i] does not contain duplicates elements.
 * 
 * 
 */
class Solution
{
public:
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {
        unordered_map<int, vector<int>> group_items;
        for (int i = 0; i < n; ++i)
        {
            if (group[i] == -1)
            {
                group[i] = m++;
            }
            group_items[group[i]].push_back(i);
        }

        // group graph
        vector<unordered_set<int>> g(m);
        vector<int> indegree_g(m);
        // graph
        vector<vector<int>> t(n);
        vector<int> indegree_t(n);
        for (int i = 0; i < n; ++i)
        {
            // edge from j to i
            int gi = group[i];
            for (auto j : beforeItems[i])
            {
                int gj = group[j];
                indegree_t[i]++;
                t[j].push_back(i);
                // group
                if (gi != gj)
                {
                    if (g[gj].find(gi) == g[gj].end())
                    {
                        indegree_g[gi]++;
                        g[gj].insert(gi);
                    }
                }
            }
        }
        // topological sort on groups
        vector<int> group_order;
        vector<bool> visited(m);
        queue<int> q;
        for (int i = 0; i < m; ++i)
        {
            if (indegree_g[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
        while (q.size())
        {
            int i = q.front();
            q.pop();
            group_order.push_back(i);
            for (auto j : g[i])
            {
                if (!visited[j])
                {
                    indegree_g[j]--;
                    if (indegree_g[j] == 0)
                    {
                        q.push(j);
                        visited[j] = 1;
                    }
                }
            }
        }

        if (group_order.size() != m)
        {
            return {};
        }

        cout << endl;
        // toplogical sort on each group and group i
        vector<int> res;
        vector<bool> visited2(n);
        for (int k = 0; k < m; ++k)
        {
            // inside each group
            int cnt = 0;
            int gid = group_order[k];
            auto &items = group_items[gid];
            queue<int> q;
            for (auto it : items)
            {
                if (indegree_t[it] == 0)
                {
                    visited2[it] = 1;

                    q.push(it);
                }
            }
            while (q.size())
            {
                int from = q.front();
                q.pop();
                res.push_back(from);
                ++cnt;
                for (auto &to : t[from])
                {
                    --indegree_t[to];
                    if (indegree_t[to] == 0 && gid == group[to])
                    {
                        q.push(to);
                        visited2[to] = 1;
                    }
                }
            }
            if (cnt != items.size())
            {

                return {};
            }
        }
        return res;
    }
};
