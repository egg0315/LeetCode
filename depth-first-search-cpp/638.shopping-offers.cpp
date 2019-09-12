/*
 * @lc app=leetcode id=638 lang=cpp
 *
 * [638] Shopping Offers
 */
class Solution {
public:
  int shoppingOffers(vector<int> &price, vector<vector<int>> &special,
                     vector<int> &needs) {
    int res = INT_MAX;
    dfs(price, special, needs, 0, res);
    return res;
  }

  void dfs(vector<int> &price, vector<vector<int>> &special, vector<int> &needs,
           int cur, int &res) {
    int cost = cur;
    for (int i = 0; i < needs.size(); ++i) {
      cost += price[i] * needs[i];
    }
    res = min(cost, res);

    for (auto &offer : special) {
      if (valid(offer, needs)) {
        auto remain = subtract(needs, offer);
        dfs(price, special, remain, cur + offer.back(), res);
      }
    }
  }

  bool valid(vector<int> &offer, vector<int> &need) {
    int n = need.size();
    for (int i = 0; i < n; ++i) {
      if (offer[i] > need[i]) {
        return false;
      }
    }
    return true;
  }

  vector<int> subtract(vector<int> &need, vector<int> &offer) {
    vector<int> res(need.size());
    for (int i = 0; i < need.size(); ++i)
      res[i] = need[i] - offer[i];
    return res;
  }
};
