/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 *
 * https://leetcode.com/problems/all-oone-data-structure/description/
 *
 * algorithms
 * Hard (30.49%)
 * Likes:    409
 * Dislikes: 59
 * Total Accepted:    22K
 * Total Submissions: 71.8K
 * Testcase Example:  '["AllOne","getMaxKey","getMinKey"]\n[[],[],[]]'
 *
 * Implement a data structure supporting the following operations:
 * 
 * 
 * 
 * Inc(Key) - Inserts a new key  with value 1. Or increments an existing key by
 * 1. Key is guaranteed to be a non-empty string.
 * Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise
 * decrements an existing key by 1. If the key does not exist, this function
 * does nothing. Key is guaranteed to be a non-empty string.
 * GetMaxKey() - Returns one of the keys with maximal value. If no element
 * exists, return an empty string "".
 * GetMinKey() - Returns one of the keys with minimal value. If no element
 * exists, return an empty string "".
 * 
 * 
 * 
 * 
 * Challenge: Perform all these in O(1) time complexity.
 * 
 */
class AllOne
{
public:
    /** Initialize your data structure here. */
    AllOne()
    {
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key)
    {
        // new key
        if (iters.find(key) == iters.end())
        {
            if (buckets.empty() || buckets.begin()->first != 1)
            {
                buckets.insert(buckets.begin(), {1, {key}});
            }
            else
            {
                buckets.begin()->second.insert(key);
            }
            iters[key] = buckets.begin();
        }
        else
        {
            auto it = iters[key];
            auto next = it;
            ++next;
            if (next != buckets.end() && next->first == it->first + 1)
            {
                next->second.insert(key);
            }
            else
            {
                next = buckets.insert(next, {it->first + 1, {key}});
            }
            iters[key] = next;
            // deal with old
            it->second.erase(key);
            if (it->second.empty())
                buckets.erase(it);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key)
    {
        if (iters.find(key) != iters.end())
        {
            auto it = iters[key], prev = it;
            if (it != buckets.begin())
            {
                --prev;
            }
            if (it->first != 1)
            {
                if (it == buckets.begin() || prev->first != it->first - 1)
                {
                    prev = buckets.insert(it, {it->first - 1, {}});
                }
                prev->second.insert(key);
                iters[key] = prev;
            }
            else
            {
                iters.erase(key);
            }
            it->second.erase(key);
            if (it->second.empty())
            {
                buckets.erase(it);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey()
    {
        return buckets.empty() ? "" : *buckets.rbegin()->second.begin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey()
    {
        return buckets.empty() ? "" : *buckets.begin()->second.begin();
    }

private:
    list<pair<int, unordered_set<string>>> buckets;
    unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> iters;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
