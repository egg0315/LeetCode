/*
 * @lc app=leetcode id=786 lang=cpp
 *
 * [786] K-th Smallest Prime Fraction
 *
 * https://leetcode.com/problems/k-th-smallest-prime-fraction/description/
 *
 * algorithms
 * Hard (40.77%)
 * Likes:    254
 * Dislikes: 14
 * Total Accepted:    9.4K
 * Total Submissions: 23K
 * Testcase Example:  '[1,2,3,5]\n3'
 *
 * A sorted list A contains 1, plus some number of primes.  Then, for every p <
 * q in the list, we consider the fraction p/q.
 * 
 * What is the K-th smallest fraction considered?  Return your answer as an
 * array of ints, where answer[0] = p and answer[1] = q.
 * 
 * 
 * Examples:
 * Input: A = [1, 2, 3, 5], K = 3
 * Output: [2, 5]
 * Explanation:
 * The fractions to be considered in sorted order are:
 * 1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
 * The third fraction is 2/5.
 * 
 * Input: A = [1, 7], K = 1
 * Output: [1, 7]
 * 
 * 
 * Note:
 * 
 * 
 * A will have length between 2 and 2000.
 * Each A[i] will be between 1 and 30000.
 * K will be between 1 and A.length * (A.length - 1) / 2.
 * 
 */
class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &A, int K)
    {
        int n = A.size();
        // pq of size n
        double low = 0.0, high = 1.0, mid;
        // constant iterations, 20 iteration will have high - low < 1e-6
        // each search will cost nlogn
        while (low < high)
        {
            mid = (low + high) / 2.0;
            // count smaller than mid;
            int count = 0;
            for (auto den : A)
            {
                int limit = mid * den;
                // count smaller and equal than limit
                int c = upper_bound(A.begin(), A.end(), limit) - A.begin();
                count += c;
            }
            if (count == K)
                break;
            else if (count > K)
                high = mid;
            else
                low = mid;
        }
        // get largest fraction smaller than mid
        // O(n^2)
        double maxx = 0;
        vector<int> res;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                double d = (double)A[i] / A[j];
                if (d <= mid && d > maxx)
                {
                    maxx = d;
                    res = {A[i], A[j]};
                }
            }
        }
        return res;
    }
};
