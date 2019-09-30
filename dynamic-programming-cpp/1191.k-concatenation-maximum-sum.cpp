/*
 * @lc app=leetcode id=1191 lang=cpp
 *
 * [1191] K-Concatenation Maximum Sum
 *
 * https://leetcode.com/problems/k-concatenation-maximum-sum/description/
 *
 * algorithms
 * Medium (23.62%)
 * Likes:    117
 * Dislikes: 15
 * Total Accepted:    4.6K
 * Total Submissions: 19.4K
 * Testcase Example:  '[1,2]\n3'
 *
 * Given an integer array arr and an integer k, modify the array by repeating
 * it k times.
 * 
 * For example, if arr = [1, 2] and k = 3 then the modified array will be [1,
 * 2, 1, 2, 1, 2].
 * 
 * Return the maximum sub-array sum in the modified array. Note that the length
 * of the sub-array can be 0 and its sum in that case is 0.
 * 
 * As the answer can be very large, return the answer modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,2], k = 3
 * Output: 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,-2,1], k = 5
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [-1,-2], k = 7
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^5
 * 1 <= k <= 10^5
 * -10^4 <= arr[i] <= 10^4
 * 
 */
class Solution
{
public:
    const int mod = 1e9 + 7;
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        vector<int> buf = arr;
        copy(arr.begin(), arr.end(), back_inserter(buf));
        long sum = accumulate(arr.begin(), arr.end(), 0L);
        if (k == 1)
            return maxSum(arr);
        if (k == 2 || sum <= 0)
            return maxSum(buf);
        return (sum * (k - 2)) % mod + maxSum(buf);
    }

    long maxSum(vector<int> &v)
    {
        long mx = v[0];
        long cur = v[0];
        for (int i = 1; i < v.size(); ++i)
        {
            cur = max(cur + v[i], (long)v[i]);
            mx = max(mx, cur);
        }
        return mx < 0 ? 0 : mx;
    }
};
