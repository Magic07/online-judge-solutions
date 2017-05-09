#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

int*** solution;

bool IsFull(const int col, const int line, const int m, const int status) {
  // |line| may be 0 or 1, correspoding to the first line or second line.
  int move = (1 - line) * m;
  move += (m - 1 - col);
  return (status >> move) % 2;
}

int Sum(const int row,
        const int col,
        const int n,
        const int m,
        const int status) {
  if (solution[row][col][status] != -1)
    return solution[row][col][status];
  int answer(0);
  if (IsFull(col, 0, m, status)) {
    if (row == n - 1 && col == m - 1) {
      answer = 1;
    } else if (col < m - 1) {
      answer = Sum(row, col + 1, n, m, status);
    } else if (row < n - 1) {
      answer = Sum(row + 1, 0, n, m, (status << m) % (1 << (m << 1)));
    } else {
      assert(false);
    }
  } else {
    if ((col == m - 1 || IsFull(col + 1, 0, m, status)) &&
        (row == n - 1 || IsFull(col, 1, m, status))) {
      // Conflict
      answer = 0;
    } else if (col < m - 1 && !IsFull(col + 1, 0, m, status) &&
               ((row == n - 1) || IsFull(col, 1, m, status))) {
      // Mark right side.
      answer =
          Sum(row, col, n, m,
              status + (1 << (m + m - 1 - col - 1)) + (1 << (m + m - col - 1)));
    } else if (col == m - 1 ||
               IsFull(col + 1, 0, m, status) &&
                   (row < n - 1 && !IsFull(col, 1, m, status))) {
      // Mark bottom one.
      answer = Sum(row, 0, n, m,
                   status + (1 << (m + m - 1 - col)) + (1 << (m - 1 - col)));
    } else {
      answer = Sum(row, col, n, m,
                   status + (1 << (m + m - 1 - col - 1)) +
                       (1 << (m + m - col - 1))) +
               Sum(row, col, n, m,
                   status + (1 << (m - 1 - col)) + (1 << (m + m - col - 1)));
    }
  }
  solution[row][col][status] = answer % 1000000007;
  return answer % 1000000007;
}

void Alloc(int n, int m) {
  int p(1 << (m << 1));
  solution = static_cast<int***>(malloc(sizeof(int**) * n));
  for (int i = 0; i < n; i++) {
    solution[i] = static_cast<int**>(malloc(sizeof(int*) * m));
    for (int j = 0; j < m; j++) {
      solution[i][j] = static_cast<int*>(malloc(sizeof(int) * p));
      memset(solution[i][j], 0, sizeof(int) * p);
      for (int k = 0; k < (1 << (m << 1)); k++) {
        solution[i][j][k] = -1;
      }
    }
  }
}

int main() {
  int n(0), m(0);
  cin >> n >> m;
  Alloc(n, m);
  cout << Sum(0, 0, n, m, 0);
}
