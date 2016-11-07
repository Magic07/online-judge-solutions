#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

bool FindAugmentPath(const unordered_map<int, list<int>>& graph,
                     int x,
                     bool* used,
                     int* path) {
  if (graph.find(x) == graph.end())
    return false;
  auto associated_vs = graph.find(x)->second;
  for (auto v : associated_vs) {
    if (!used[v]) {
      used[v] = true;
      if (path[v] == 0 || FindAugmentPath(graph, path[v], used, path)) {
        path[v] = x;
        return true;
      }
    }
  }
  return false;
}

int main() {
  int n_length(0);
  int m_length(0);
  scanf("%d %d", &n_length, &m_length);
  bool* used = (bool*)malloc(sizeof(bool) * (n_length + 1));
  memset(used, 0, sizeof(bool) * (n_length + 1));
  int* path = (int*)malloc(sizeof(int) * (n_length + 1));
  memset(path, 0, sizeof(int) * (n_length + 1));
  unordered_map<int, list<int>> edges;
  // Edges
  for (int i = 0; i < m_length; i++) {
    int tail(0);
    int head(0);
    cin >> tail >> head;
    edges[tail].push_back(head);
  }
  int found_path(0);
  for (int i = 1; i < n_length + 1; i++) {
    if (FindAugmentPath(edges, i, used, path)) {
      found_path++;
    }
    memset(used, 0, sizeof(bool) * (n_length + 1));
  }
  cout << n_length - found_path << endl;
  return 0;
}
