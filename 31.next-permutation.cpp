/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.20%)
 * Likes:    2299
 * Dislikes: 749
 * Total Accepted:    282.6K
 * Total Submissions: 905.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // if decreasing order
        if (decreasing(nums))
        {
            sort(nums.begin(), nums.end());
            return;
        }

        // direction of search is very important
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int j = nums.size() - 1; j > i; j--)
            {
                if (nums[j] > nums[i])
                {
                    swap(nums[i], nums[j]);
                    //cout << "swap " << nums[i] << " " << nums[j] << endl;
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
        return;
    }
    bool decreasing(vector<int> nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] < nums[i + 1])
                return false;
        }
        return true;
    }

    // [4,2,0,2,3,2,0]
};
// @lc code=end
