#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<set<int>> graph;
int answer[101][100];
int* rate;

void Input() {
  cin >> N >> M;
  rate = static_cast<int*>(malloc((N + 1) * sizeof(int)));
  memset(rate, 0, sizeof(int) * (N + 1));
  for (int i = 1; i <= N; i++) {
    cin >> rate[i];
  }
  graph.resize(N + 1);  // Index starts from 1.
  for (int i = 0; i < N - 1; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    graph[v1].insert(v2);
    graph[v2].insert(v1);
  }
  for (int i = 0; i < 101; i++) {
    answer[i][0] = -1;
    for (int j = 1; j < 100; j++) {
      answer[i][j] = 0;
    }
  }
}

void Dfs(int root) {
  answer[root][0] = 0;
  answer[root][1] = rate[root];
  for (int child : graph[root]) {
    if (answer[child][0] != -1)
      continue;
    Dfs(child);
    for (int i = M; i >= 2; i--) {
      for (int j = 0; j < i; j++) {
        answer[root][i] =
            max(answer[root][i], answer[root][i - j] + answer[child][j]);
      }
    }
  }
}

int main() {
  Input();
  Dfs(1);
  cout << answer[1][M];
}
