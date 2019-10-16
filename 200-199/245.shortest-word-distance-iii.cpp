/*
 * @lc app=leetcode id=245 lang=cpp
 *
 * [245] Shortest Word Distance III
 *
 * https://leetcode.com/problems/shortest-word-distance-iii/description/
 *
 * algorithms
 * Medium (54.04%)
 * Likes:    135
 * Dislikes: 59
 * Total Accepted:    41.9K
 * Total Submissions: 77.4K
 * Testcase Example:  '["practice", "makes", "perfect", "coding",
 * "makes"]\n"makes"\n"coding"'
 *
 * Given a list of words and two words word1 and word2, return the shortest
 * distance between these two words in the list.
 *
 * word1 and word2 may be the same and they represent two individual words in
 * the list.
 *
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 *
 *
 * Input: word1 = “makes”, word2 = “coding”
 * Output: 1
 *
 *
 *
 * Input: word1 = "makes", word2 = "makes"
 * Output: 3
 *
 *
 * Note:
 * You may assume word1 and word2 are both in the list.
 *
 */
class Solution {
public:
  int shortestWordDistance(vector<string> &words, string word1, string word2) {
    int res = words.size();
    int index1 = -1, index2 = -1;
    for (int i = 0; i < words.size(); ++i) {
      if (words[i] == word1) {
        index1 = i;
      }
      if (words[i] == word2) {
        if (word1 == word2) {
          index1 = index2;
        }
        index2 = i;
      }
      if (index1 != -1 && index2 != -1)
        res = min(res, abs(index1 - index2));
    }
    return res;
  }
};
