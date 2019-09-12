/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 */
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
  unordered_map<int, Employee *> m;
  int getImportance(vector<Employee *> v, int id) {
    for (auto e : v)
      m[e->id] = e;
    int sum = 0;
    dfs(m[id], sum);
    return sum;
  }

  void dfs(Employee *e, int &sum) {
    sum += e->importance;
    for (auto &j : e->subordinates) {
      dfs(m[j], sum);
    }
  }
};
