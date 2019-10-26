/*
 * @lc app=leetcode id=321 lang=cpp
 *
 * [321] Create Maximum Number
 *
 * https://leetcode.com/problems/create-maximum-number/description/
 *
 * algorithms
 * Hard (25.97%)
 * Likes:    473
 * Dislikes: 167
 * Total Accepted:    33.5K
 * Total Submissions: 128.9K
 * Testcase Example:  '[3,4,6,5]\n[9,1,2,5,8,3]\n5'
 *
 * Given two arrays of length m and n with digits 0-9 representing two numbers.
 * Create the maximum number of length k <= m + n from digits of the two. The
 * relative order of the digits from the same array must be preserved. Return
 * an array of the k digits.
 * 
 * Note: You should try to optimize your time and space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * nums1 = [3, 4, 6, 5]
 * nums2 = [9, 1, 2, 5, 8, 3]
 * k = 5
 * Output:
 * [9, 8, 6, 5, 3]
 * 
 * Example 2:
 * 
 * 
 * Input:
 * nums1 = [6, 7]
 * nums2 = [6, 0, 4]
 * k = 5
 * Output:
 * [6, 7, 6, 0, 4]
 * 
 * Example 3:
 * 
 * 
 * Input:
 * nums1 = [3, 9]
 * nums2 = [8, 9]
 * k = 3
 * Output:
 * [9, 8, 9]
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        if (k == 0)
            return {};
        if (!nums1.size() || !nums2.size())
        {
            return nums1.size() ? maxSingle(nums1, k) : maxSingle(nums2, k);
        }
        int m = nums1.size(), n = nums2.size();
        vector<int> res;
        for (int sz = max(0, k - n); sz <= min(m, k); ++sz)
        {
            auto v1 = maxSingle(nums1, sz);
            auto v2 = maxSingle(nums2, k - sz);
            auto tmp = merge(v1, v2);
            if (res.size() == 0 || res < tmp)
            {
                res = tmp;
            }
        }
        return res;
    }

    vector<int> maxSingle(vector<int> &nums, int k)
    {
        if (k == 0)
            return {};
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while (res.size() && res.back() < nums[i] && res.size() - 1 + n - i >= k)
            {
                res.pop_back();
            }
            res.push_back(nums[i]);
        }
        while (res.size() > k)
            res.pop_back();
        return res;
    }
    vector<int> merge(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        auto it1 = nums1.begin(), end1 = nums1.end();
        auto it2 = nums2.begin(), end2 = nums2.end();
        while (it1 < end1 || it2 < end2)
        {
            // this must be lexicographical compare
            if (lexicographical_compare(it1, end1, it2, end2))
            {
                res.push_back(*it2++);
            }
            else
                res.push_back(*it1++);
        }
        return res;
    }
};
// @lc code=end
