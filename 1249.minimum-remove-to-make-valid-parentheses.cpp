class Solution
{
public:
    bool isGoodArray(vector<int> &nums)
    {
        if (nums.size() == 0)
            return false;
        if (nums.size() == 1)
            return nums[0] == 1;
        int gcd = __gcd(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i)
            gcd = __gcd(nums[i], gcd);
        if (gcd != 1)
            return false;
        return true;
    }
};