/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
 *
 * https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
 *
 * algorithms
 * Hard (29.95%)
 * Likes:    621
 * Dislikes: 21
 * Total Accepted:    22.9K
 * Total Submissions: 76.3K
 * Testcase Example:  '[1,3,1]\n1'
 *
 * Given an integer array, return the k-th smallest distance among all the
 * pairs. The distance of a pair (A, B) is defined as the absolute difference
 * between A and B. 
 * 
 * Example 1:
 * 
 * Input:
 * nums = [1,3,1]
 * k = 1
 * Output: 0 
 * Explanation:
 * Here are all the pairs:
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * Then the 1st smallest distance pair is (1,1), and its distance is 0.
 * 
 * 
 * 
 * Note:
 * 
 * 2 .
 * 0 .
 * 1 .
 * 
 * 
 */
class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int K)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int lo = 0, hi = nums.back() - nums[0], mid;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            int count = countSmallerEqual(nums, mid);
            if (count < K)
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

    int countSmallerEqual(vector<int> &nums, int val)
    {
        int n = nums.size();
        int i = n - 2, j = n - 1;
        int count = 0;
        while (i >= 0 && j >= 0)
        {
            if (j > i && nums[j] - nums[i] > val)
            {
                --j;
            }
            else
            {
                count += j - i;
                --i;
            }
        }
        return count;
    }

    // PQ solution TLE
    // int smallestDistancePair(vector<int>& nums, int K) {
    //     int n = nums.size();
    //     sort(begin(nums), end(nums));
    //     // {diff, {i, j}}
    //     priority_queue<pair<int, pair<int, int>>> pq;
    //     for(int i = 0; i < n-1; ++i) {
    //         pq.push({-abs(nums[i]- nums[i+1]), {i, i+1}});
    //     }
    //     auto cur = pq.top();
    //     int i, j;
    //     for(int k =0; k < K; ++k) {
    //         cur = pq.top();
    //         pq.pop();
    //         i = cur.second.first;
    //         j = cur.second.second;
    //         if(j < n-1) {
    //             pq.push({-abs(nums[j+1]- nums[i]), {i, j+1}});
    //         }
    //     }
    //     return -cur.first;
    // }
};
