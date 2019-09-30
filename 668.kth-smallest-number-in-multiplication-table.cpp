/*
 * @lc app=leetcode id=668 lang=cpp
 *
 * [668] Kth Smallest Number in Multiplication Table
 *
 * https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
 *
 * algorithms
 * Hard (42.82%)
 * Likes:    383
 * Dislikes: 19
 * Total Accepted:    14.5K
 * Total Submissions: 34K
 * Testcase Example:  '3\n3\n5'
 *
 * 
 * Nearly every one have used the Multiplication Table. But could you find out
 * the k-th smallest number quickly from the multiplication table?
 * 
 * 
 * 
 * Given the height m and the length n of a m * n Multiplication Table, and a
 * positive integer k, you need to return the k-th smallest number in this
 * table.
 * 
 * 
 * Example 1:
 * 
 * Input: m = 3, n = 3, k = 5
 * Output: 
 * Explanation: 
 * The Multiplication Table:
 * 1    2    3
 * 2    4    6
 * 3    6    9
 * 
 * The 5-th smallest number is 3 (1, 2, 2, 3, 3).
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: m = 2, n = 3, k = 6
 * Output: 
 * Explanation: 
 * The Multiplication Table:
 * 1    2    3
 * 2    4    6
 * 
 * The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The m and n will be in the range [1, 30000].
 * The k will be in the range [1, m * n]
 * 
 * 
 */
class Solution
{
public:
    int findKthNumber(int m, int n, int k)
    {
        int lo = 1, hi = m * n;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int c = countSmallerEqual(mid, m, n);
            if (c < k)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return lo;
    }

    int countSmallerEqual(int val, int m, int n)
    {
        int i = 1, j = n;
        int count = 0;
        while (i <= m && j >= 1)
        {
            if (i * j > val)
            {
                --j;
            }
            else
            {
                count += j;
                ++i;
            }
        }
        return count;
    }
};
