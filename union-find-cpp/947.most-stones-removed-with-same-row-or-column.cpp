/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */
class Solution {
public:
  int removeStones(vector<vector<int>> &stones) {
    int n = stones.size();
    unordered_map<int, vector<int>> rows;
    unordered_map<int, vector<int>> cols;
    for (int i = 0; i < n; ++i) {
      int x = stones[i][0], y = stones[i][1];
      rows[x].push_back(i);
      cols[y].push_back(i);
    }
    disjoint_set ds;
    ds.init(n);
    for (auto &[x, v] : rows) {
      for (int i = 1; i < v.size(); ++i) {
        ds.join(v[i], v[i - 1]);
      }
    }
    for (auto &[y, v] : cols) {
      for (int i = 1; i < v.size(); ++i) {
        ds.join(v[i], v[i - 1]);
      }
    }
    return n - ds.sz;
  }

  class disjoint_set {
  public:
    int sz;
    vector<int> id;

    void init(int n) {
      sz = n;
      id.resize(n);
      iota(begin(id), end(id), 0);
    }

    void join(int p, int q) {
      int pid = find(p);
      int qid = find(q);
      if (pid == qid)
        return;
      --sz;
      id[pid] = qid;
    }

    int find(int p) {
      int r = p;
      while (r != id[r])
        r = id[r];
      int x = p;
      while (x != r) {
        int tmp = id[x];
        id[x] = r;
        x = tmp;
      }
      return r;
    }
  };
};
