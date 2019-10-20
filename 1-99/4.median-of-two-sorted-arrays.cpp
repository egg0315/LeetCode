/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (27.35%)
 * Likes:    5222
 * Dislikes: 758
 * Total Accepted:    526K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &v1, vector<int> &v2)
    {
        int k = v1.size() + v2.size() + 1;
        double low = findKth(v1, 0, v2, 0, k / 2);
        double high = findKth(v1, 0, v2, 0, (k + 1) / 2);
        return (findKth(v1, 0, v2, 0, k / 2) + findKth(v1, 0, v2, 0, (k + 1) / 2)) / 2.0;
    }

    int findKth(vector<int> &v1, int s1, vector<int> &v2, int s2, int k)
    {
        int sz1 = v1.size(), sz2 = v2.size();
        int m = v1.size() - s1, n = v2.size() - s2;
        if (m > n)
            return findKth(v2, s2, v1, s1, k);
        if (m == 0)
            return v2[s2 + k - 1];
        if (k == 1)
            return min(v1[s1], v2[s2]);
        int i = min(sz1, s1 + k / 2);
        int j = min(sz2, s2 + k / 2);
        if (v1[i - 1] < v2[j - 1])
        {
            return findKth(v1, i, v2, s2, k - (i - s1));
        }
        else
            return findKth(v1, s1, v2, j, k - (j - s2));
    }
};
// @lc code=end
