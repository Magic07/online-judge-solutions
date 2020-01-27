#include <vector>

class Solution {
 public:
  int currentDfn;
  vector<vector<int>> answer;
  void dfs(int start,
           const vector<vector<int>>& graph,
           vector<int>& dfn,
           vector<int>& low,
           int parent) {
    for (const auto& v : graph[start]) {
      if (v == parent) {
        continue;
      }
      if (dfn[v] == -1) {
        low[v] = currentDfn;
        dfn[v] = currentDfn++;
        dfs(v, graph, dfn, low, start);
        low[start] = min(low[start], low[v]);
        if (low[v] > dfn[start]) {
          answer.push_back({start, v});
        }
      } else {
        low[start] = min(low[start], dfn[v]);
      }
    }
  }
  void resizeAndFill(vector<int>& v, int n) {
    v.resize(n);
    fill(v.begin(), v.end(), -1);
  }
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>>& connections) {
    vector<vector<int>> graph;
    vector<int> dfn, low;
    graph.resize(n);
    resizeAndFill(dfn, n);
    resizeAndFill(low, n);
    currentDfn = 0;
    for (const auto& con : connections) {
      graph[con[0]].push_back(con[1]);
      graph[con[1]].push_back(con[0]);
    }
    dfs(0, graph, dfn, low, 0);
    return answer;
  }
};