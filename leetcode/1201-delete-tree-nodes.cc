#include <vector>

using namespace std;

class Solution {
 public:
  void deleteSubTree(int root,
                     vector<vector<int>>& children,
                     vector<bool>& deleted) {
    deleted[root] = true;
    if (children[root].size() != 0) {
      for (int c : children[root]) {
        deleteSubTree(c, children, deleted);
      }
    }
  }
  int dfs(int root,
          vector<vector<int>>& children,
          vector<int>& value,
          vector<bool>& deleted) {
    if (children[root].size() != 0) {
      for (int c : children[root]) {
        value[root] += dfs(c, children, value, deleted);
      }
    }
    if (value[root] == 0) {
      deleteSubTree(root, children, deleted);
      return 0;
    }
    return value[root];
  }
  int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
    int root(-1);
    vector<vector<int>> children(parent.size());
    for (int i = 0; i < parent.size(); i++) {
      if (parent[i] == -1) {
        root = i;
        continue;
      } else {
        children[parent[i]].push_back(i);
      }
    }
    vector<bool> deleted(parent.size());
    dfs(root, children, value, deleted);
    int deletedCount(0);
    for (bool d : deleted) {
      if (d) {
        deletedCount++;
      }
    }
    return parent.size() - deletedCount;
  }
};