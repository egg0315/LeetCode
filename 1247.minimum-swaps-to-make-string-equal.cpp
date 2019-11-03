class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return -1;
        unordered_map<char, int> mp;
        for (auto &c : s1)
            mp[c]++;
        for (auto &c : s2)
            mp[c]++;
        if (mp['x'] % 2 || mp['y'] % 2)
            return -1;
        // x,y    y,x   xx,     yy
        int a = 0, b = 0； for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] == 'x' && s2[i] == 'y')
                a++;
            else if (s1[i] == 'y' && s2[i] == 'x')
                b++;
        }
        return (a + 1) / 2 + (b + 1) / 2;
    }
};