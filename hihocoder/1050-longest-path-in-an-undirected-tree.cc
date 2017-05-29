#include <vector>
#include <iostream>
#include <unordered_map>
#include <cassert>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Node {
  int value;
  vector<Node*> children;
  explicit Node(int v) : value(v) {}
};

// Return the max depth.
int Dfs(const Node* root, int& longest) {
  int first = 0;
  int second = 0;
  for (auto child : root->children) {
    int depth = Dfs(child, longest);
    if (depth > second) {
      second = depth;
      if (second > first) {
        swap(first, second);
      }
    }
  }
  longest = max(longest, first + second);
  return first + 1;
}

int main() {
  int vetex_num;
  cin >> vetex_num;
  if (vetex_num < 2) {
    cout << 0;
    return 0;
  }
  unordered_map<int, Node*> vetex_map;
  Node* root(nullptr);
  int longest = 0;
  for (int i = 0; i < vetex_num - 1; i++) {
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    if (i == 0) {
      root = new Node(v1);
      vetex_map[v1] = root;
    }
    assert(vetex_map.find(v1) != vetex_map.end());
    Node* p = vetex_map[v1];
    Node* child = new Node(v2);
    p->children.push_back(child);
    vetex_map[v2] = child;
  }
  Dfs(root, longest);
  cout << longest;
}
