/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 *
 * https://leetcode.com/problems/minimum-absolute-difference/description/
 *
 * algorithms
 * Easy (66.58%)
 * Likes:    11
 * Dislikes: 3
 * Total Accepted:    5K
 * Total Submissions: 7.5K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given an array of distinct integers arr, find all pairs of elements with the
 * minimum absolute difference of any two elements. 
 * 
 * Return a list of pairs in ascending order(with respect to pairs), each pair
 * [a, b] follows
 * 
 * 
 * a, b are from arr
 * a < b
 * b - a equals to the minimum absolute difference of any two elements in
 * arr
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [4,2,1,3]
 * Output: [[1,2],[2,3],[3,4]]
 * Explanation: The minimum absolute difference is 1. List all pairs with
 * difference equal to 1 in ascending order.
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,3,6,10,15]
 * Output: [[1,3]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [3,8,-10,23,19,-4,-14,27]
 * Output: [[-14,-10],[19,23],[23,27]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= arr.length <= 10^5
 * -10^6 <= arr[i] <= 10^6
 * 
 * 
 */
class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &a)
    {
        sort(a.begin(), a.end());
        int min_dif = a[1] - a[0];
        vector<vector<int>> res = {{a[0], a[1]}};
        for (int i = 2; i < a.size(); ++i)
        {
            if (a[i] - a[i - 1] == min_dif)
            {
                res.push_back({a[i - 1], a[i]});
            }
            else if (a[i] - a[i - 1] < min_dif)
            {
                min_dif = a[i] - a[i - 1];
                res = {{a[i - 1], a[i]}};
            }
        }
        return res;
    }
};
