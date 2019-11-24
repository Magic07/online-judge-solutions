class Solution {
 public:
  double dfs(const string& start,
             const string& target,
             unordered_map<string, unordered_map<string, double>>& graph,
             set<string>& visited) {
    visited.insert(start);
    for (auto& edge : graph[start]) {
      if (visited.count(edge.first) > 0) {
        continue;
      }
      if (edge.first == target) {
        return edge.second;
      }
      double answer = dfs(edge.first, target, graph, visited);
      if (answer != 0) {
        return answer * edge.second;
      }
    }
    return 0;
  }
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>> graph;
    for (int i = 0; i < equations.size(); i++) {
      graph[equations[i][0]][equations[i][1]] = values[i];
      graph[equations[i][1]][equations[i][0]] = 1 / values[i];
    }
    vector<double> answers;
    for (const auto& q : queries) {
      if (q[0] == q[1]) {
        if (graph.find(q[0]) == graph.end()) {
          answers.push_back(-1);
        } else {
          answers.push_back(1);
        }
        continue;
      }
      set<string> visited;
      double answer = dfs(q[0], q[1], graph, visited);
      if (answer == 0) {
        answers.push_back(-1);
      } else {
        answers.push_back(answer);
        graph[q[0]][q[1]] = answer;
      }
    }
    return answers;
  }
};