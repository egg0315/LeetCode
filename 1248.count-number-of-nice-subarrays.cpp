class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> count;
        count[0] = 1;
        int res = 0;
        int c = 0;
        for (int i = 0; i < n; ++i)
        {
            c += (nums[i] % 2);
            count[c]++;
            res += (count[c - k]);
        }
        return res;
    }
};