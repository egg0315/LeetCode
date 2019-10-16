/*
 * @lc app=leetcode id=444 lang=cpp
 *
 * [444] Sequence Reconstruction
 *
 * https://leetcode.com/problems/sequence-reconstruction/description/
 *
 * algorithms
 * Medium (20.65%)
 * Likes:    175
 * Dislikes: 585
 * Total Accepted:    18.4K
 * Total Submissions: 89.3K
 * Testcase Example:  '[1,2,3]\n[[1,2],[1,3]]'
 *
 * Check whether the original sequence org can be uniquely reconstructed from
 * the sequences in seqs. The org sequence is a permutation of the integers
 * from 1 to n, with 1 ≤ n ≤ 10^4. Reconstruction means building a shortest
 * common supersequence of the sequences in seqs (i.e., a shortest sequence so
 * that all sequences in seqs are subsequences of it). Determine whether there
 * is only one sequence that can be reconstructed from seqs and it is the org
 * sequence.
 *
 * Example 1:
 *
 * Input:
 * org: [1,2,3], seqs: [[1,2],[1,3]]
 *
 * Output:
 * false
 *
 * Explanation:
 * [1,2,3] is not the only one sequence that can be reconstructed, because
 * [1,3,2] is also a valid sequence that can be reconstructed.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * org: [1,2,3], seqs: [[1,2]]
 *
 * Output:
 * false
 *
 * Explanation:
 * The reconstructed sequence can only be [1,2].
 *
 *
 *
 * Example 3:
 *
 * Input:
 * org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]
 *
 * Output:
 * true
 *
 * Explanation:
 * The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original
 * sequence [1,2,3].
 *
 *
 *
 * Example 4:
 *
 * Input:
 * org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]
 *
 * Output:
 * true
 *
 *
 *
 *
 * UPDATE (2017/1/8):
 * The seqs parameter had been changed to a list of list of strings (instead of
 * a 2d array of strings). Please reload the code definition to get the latest
 * changes.
 *
 */
// stupid test case
class Solution {
public:
  bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
    int n = org.size();

    vector<bool> seen(n);
    vector<vector<int>> g(n + 1);
    vector<int> indegree(n + 1);

    for (auto &seq : seqs) {
      if (seq.size() == 0)
        continue;
      if (any_of(seq.begin(), seq.end(), [n](int x) { return x < 1 || x > n; }))
        return false;
      seen[seq[0] - 1] = true;
      for (int i = 1; i < seq.size(); ++i) {
        seen[seq[i] - 1] = true;
        indegree[seq[i]]++;
        g[seq[i - 1]].push_back(seq[i]);
      }
    }
    if (any_of(seen.begin(), seen.end(), [](bool x) { return x == false; }))
      return false;

    vector<bool> used(n + 1);
    vector<int> order;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
      if (!used[i] && indegree[i] == 0) {
        q.push(i);
        used[i] = 1;
      }
    }
    while (q.size()) {
      if (q.size() != 1)
        return false;
      int cur = q.front();
      order.push_back(cur);
      q.pop();
      for (auto j : g[cur]) {
        if (--indegree[j] == 0) {
          q.push(j);
        }
      }
    }
    return order == org;
  }
};
