#include <vector>

using namespace std;

class Solution {
 public:
  int answer = 0;
  int diameter(int current, int parent, unordered_map<int, vector<int>>& tree) {
    if (tree[current].size() == 1 && tree[current][0] == parent) {
      return 1;
    }
    int max1 = 0, max2 = 0;
    for (int node : tree[current]) {
      if (node == parent) {
        continue;
      }
      int depth = diameter(node, current, tree);
      if (depth > max1) {
        max2 = max1;
        max1 = depth;
      } else if (depth > max2) {
        max2 = depth;
      }
    }
    answer = max(answer, max1 + max2);
    return max1 + 1;
  }

  int treeDiameter(vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> tree;
    for (const auto& edge : edges) {
      if (std::find(tree[edge[0]].begin(), tree[edge[0]].end(), edge[1]) ==
          tree[edge[0]].end()) {
        tree[edge[0]].push_back(edge[1]);
      }
      if (std::find(tree[edge[1]].begin(), tree[edge[1]].end(), edge[0]) ==
          tree[edge[1]].end()) {
        tree[edge[1]].push_back(edge[0]);
      }
    }
    diameter(edges[0][0], -1, tree);
    return answer;
  }
};