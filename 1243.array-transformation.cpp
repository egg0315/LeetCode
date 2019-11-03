class Solution
{
public:
    vector<int> transformArray(vector<int> &a)
    {
        int n = a.size();
        while (true)
        {
            vector<int> next(n);
            next[0] = a[0];
            next[n - 1] = a[n - 1];
            for (int i = 1; i < n - 1; ++i)
            {
                if (a[i] > a[i - 1] && a[i] > a[i + 1])
                {
                    next[i] = a[i] - 1;
                }
                else if (a[i] < a[i - 1] && a[i] < a[i + 1])
                {
                    next[i] = a[i] + 1;
                }
                else
                {
                    next[i] = a[i];
                }
            }
            if (next == a)
                break;
            a = next;
        }
        return a;
    }
};