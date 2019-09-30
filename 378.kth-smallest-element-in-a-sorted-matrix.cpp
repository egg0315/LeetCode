/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (50.75%)
 * Likes:    1449
 * Dislikes: 90
 * Total Accepted:    129.4K
 * Total Submissions: 254.8K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n^2.
 */
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1], mid;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            // count smaller than mid
            int cnt = getLessEqual(matrix, mid);
            if (cnt < k)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1; // mid is >= kth, over correct, but i will correct back by lo = mid + 1
            }
        }
        return lo;
    }
    // count how many numbers in matrix are less and equal to val
    // reduce search from nlogn to O(n)
    int getLessEqual(vector<vector<int>> &matrix, int val)
    {
        int count = 0;
        int n = matrix.size(), i = n - 1, j = 0;
        while (i >= 0 && j < n)
        {
            if (matrix[i][j] > val)
                --i;
            else
            {
                ++j;
                count += i + 1;
            }
        }
        return count;
    }
};
