#include <unordered_map>
#include <vector>

class Solution {
 public:
  set<int> visited;
  vector<unordered_map<int, vector<int>>> street;

  void initStreet() {
    street = vector<unordered_map<int, vector<int>>>(7);
    street[1] = {{1, {1, 3, 5}}, {-1, {1, 4, 6}}};
    street[2] = {{1000, {2, 5, 6}}, {-1000, {2, 3, 4}}};
    street[3] = {{-1, {-1, 4, 6}}, {1000, {2, 5, 6}}};
    street[4] = {{1, {1, 3, 5}}, {1000, {2, 5, 6}}};
    street[5] = {{-1, {1, 4, 6}}, {-1000, {2, 3, 4}}};
    street[6] = {{-1000, {2, 3, 4}}, {1, {1, 3, 5}}};
  }
  void nextPosition(vector<vector<int>>& grid, int current, queue<int>& q) {
    if (current < 0 || current % 1000 >= grid[0].size() ||
        current / 1000 >= grid.size())
      return;
    if (visited.find(current) != visited.end())
      return;
    visited.insert(current);
    for (auto& m : street[grid[current / 1000][current % 1000]]) {
      int next = current + m.first;
      if(!isValid(grid,next)){
        continue;
      }
      if (find(m.second.begin(), m.second.end(),
               grid[next / 1000][next % 1000]) != m.second.end()) {
        q.push(next);
      }
    }
  }
  bool isValid(vector<vector<int>>& grid, int current) {
    if (current < 0 || current % 1000 >= grid[0].size() ||
        current / 1000 >= grid.size())
      return false;
    return true;
  }
  bool hasValidPath(vector<vector<int>>& grid) {
    initStreet();
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int current = q.front();
      q.pop();
      if (current == (grid.size() - 1) * 1000 + grid[0].size() - 1)
        return true;
      nextPosition(grid, current, q);
    }
    return false;
  }
};