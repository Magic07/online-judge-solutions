#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

int BitMasked(int value) {
  int masked(0);
  while (value != 0) {
    if (value & 1) {
      masked++;
    }
    value >>= 1;
  }
  return masked;
}

int Clean(int n, int m, int q, int* weight) {
  int bestLength = sizeof(int) * (1 << m);
  int* best = (int*)malloc(bestLength);
  int* bestOld = (int*)malloc(bestLength);
  memset(best, 0, bestLength);
  memset(bestOld, 0, bestLength);
  for (int i = 0; i < n; i++) {
    memset(best, 0, bestLength);
    for (int j = 0; j < 1 << min(m, i + 1); j++) {
      if (BitMasked(j) <= q) {
        best[j] = max(bestOld[(j >> 1) + (1 << (m - 1))], bestOld[j >> 1]);
        if (j % 2) {
          best[j] += weight[i];
        }
      } else {
        best[j] = INT_MIN;
      }
    }
    memcpy(bestOld, best, bestLength);
  }
  int answer(0);
  for (int i = 0; i <= (1 << m); i++) {
    answer = max(answer, best[i]);
  }
  return answer;
}

int main() {
  int N(0), M(0), Q(0);
  cin >> N >> M >> Q;
  if (M > N) {
    M = N;
  }
  int* data = (int*)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    cin >> data[i];
  }
  cout << Clean(N, M, Q, data);
}
