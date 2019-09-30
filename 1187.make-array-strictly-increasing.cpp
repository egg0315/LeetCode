/*
 * @lc app=leetcode id=1187 lang=cpp
 *
 * [1187] Make Array Strictly Increasing
 *
 * https://leetcode.com/problems/make-array-strictly-increasing/description/
 *
 * algorithms
 * Hard (39.63%)
 * Likes:    144
 * Dislikes: 4
 * Total Accepted:    2.4K
 * Total Submissions: 6.1K
 * Testcase Example:  '[1,5,3,6,7]\n[1,3,2,4]'
 *
 * Given two integer arrays arr1 and arr2, return the minimum number of
 * operations (possibly zero) needed to make arr1 strictly increasing.
 * 
 * In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j
 * < arr2.length and do the assignment arr1[i] = arr2[j].
 * 
 * If there is no way to make arr1 strictly increasing, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
 * Output: 1
 * Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
 * Output: 2
 * Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6,
 * 7].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
 * Output: -1
 * Explanation: You can't make arr1 strictly increasing.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr1.length, arr2.length <= 2000
 * 0 <= arr1[i], arr2[i] <= 10^9
 * 
 * 
 * 
 */
class Solution
{
public:
    int memo[2001][2001] = {};
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {

        sort(arr2.begin(), arr2.end());
        int res = dfs(arr1, arr2, 0, 0, INT_MIN);
        return res > arr2.size() ? -1 : res - 1;
    }

    int dfs(vector<int> &a1, vector<int> &a2, int i1, int i2, int prev)
    {
        if (i1 >= a1.size())
            return 1;
        i2 = upper_bound(begin(a2) + i2, end(a2), prev) - begin(a2);
        if (memo[i1][i2])
            return memo[i1][i2];
        // replace num in a1
        auto r1 = i2 < a2.size() ? 1 + dfs(a1, a2, i1 + 1, i2, a2[i2]) : a2.size() + 1;
        // do not replace
        auto r2 = prev < a1[i1] ? dfs(a1, a2, i1 + 1, i2, a1[i1]) : a2.size() + 1;
        return memo[i1][i2] = min(r1, r2);
    }
};
