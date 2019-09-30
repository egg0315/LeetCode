/*
 * @lc app=leetcode id=1175 lang=cpp
 *
 * [1175] Prime Arrangements
 *
 * https://leetcode.com/problems/prime-arrangements/description/
 *
 * algorithms
 * Easy (50.16%)
 * Likes:    39
 * Dislikes: 74
 * Total Accepted:    5.6K
 * Total Submissions: 11.2K
 * Testcase Example:  '5'
 *
 * Return the number of permutations of 1 to n so that prime numbers are at
 * prime indices (1-indexed.)
 * 
 * (Recall that an integer is prime if and only if it is greater than 1, and
 * cannot be written as a product of two positive integers both smaller than
 * it.)
 * 
 * Since the answer may be large, return the answer modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 5
 * Output: 12
 * Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1]
 * is not because the prime number 5 is at index 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 100
 * Output: 682289015
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 100
 * 
 * 
 */
class Solution
{
public:
    const int MOD = 1e9 + 7;
    int numPrimeArrangements(int n)
    {
        int primes = 0;
        for (int i = 1; i <= n; ++i)
        {
            primes += isPrime(i);
        }
        long ans = 1;
        for (int i = 2; i <= primes; ++i)
            ans = (ans * i) % MOD;
        for (int i = 2; i <= n - primes; ++i)
            ans = (ans * i) % MOD;
        return ans;
    }

    bool isPrime(int n)
    {
        if (n == 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        for (int i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};
