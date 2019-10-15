/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 *
 * https://leetcode.com/problems/erect-the-fence/description/
 *
 * algorithms
 * Hard (34.60%)
 * Likes:    150
 * Dislikes: 157
 * Total Accepted:    7.6K
 * Total Submissions: 22.1K
 * Testcase Example:  '[[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]'
 *
 * There are some trees, where each tree is represented by (x,y) coordinate in
 * a two-dimensional garden. Your job is to fence the entire garden using the
 * minimum length of rope as it is expensive. The garden is well fenced only if
 * all the trees are enclosed. Your task is to help find the coordinates of
 * trees which are exactly located on the fence perimeter.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
 * Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
 * Explanation:
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,2],[2,2],[4,2]]
 * Output: [[1,2],[2,2],[4,2]]
 * Explanation:
 * 
 * Even you only have trees in a line, you need to use rope to enclose
 * them. 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All trees should be enclosed together. You cannot cut the rope to enclose
 * trees that will separate them in more than one group.
 * All input integers will range from 0 to 100.
 * The garden has at least one tree.
 * All coordinates are distinct.
 * Input points have NO order. No order required for output.
 * input types have been changed on April 15, 2019. Please reset to default
 * code definition to get new method signature.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> outerTrees(vector<vector<int>> &points)
    {
        sort(begin(points), end(points));
        auto it = unique(begin(points), end(points));
        points.resize(it - begin(points));
        vector<vector<int>> res;
        int n = points.size();
        for (int i = 0; i < n; ++i)
        {
            while (res.size() >= 2 && orientation(res[res.size() - 2], res.back(), points[i]) < 0)
            {
                res.pop_back();
            }
            res.push_back(points[i]);
        }
        // all points are on the same line
        if (res.size() == n)
            return res;

        for (int i = n - 2; i >= 0; --i)
        {
            while (res.size() >= 2 && orientation(res[res.size() - 2], res.back(), points[i]) < 0)
                res.pop_back();
            res.push_back(points[i]);
        }
        res.pop_back();
        return res;
    }

    int orientation(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        return a[0] * b[1] + c[0] * a[1] + b[0] * c[1] - a[0] * c[1] - b[0] * a[1] - c[0] * b[1];
    }
};
// @lc code=end
