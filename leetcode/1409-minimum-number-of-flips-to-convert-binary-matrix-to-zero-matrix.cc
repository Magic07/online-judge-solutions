#include <stack>
#include <vector>

class Solution {
 public:
  int getDecimalOfMat(vector<vector<int>> mat) {
    stack<int> s;
    for (const vector<int> row : mat) {
      for (int col : row) {
        s.push(col);
      }
    }
    int base(1);
    int answer(0);
    while (!s.empty()) {
      if (s.top() == 1) {
        answer += base;
      }
      base *= 2;
      s.pop();
    }
    return answer;
  }
  void flip(vector<vector<int>>& mat, int row, int col) {
    mat[row][col] ^= 1;
    if (row != 0) {
      mat[row - 1][col] ^= 1;
    }
    if (row != mat.size() - 1) {
      mat[row + 1][col] ^= 1;
    }
    if (col != 0) {
      mat[row][col - 1] ^= 1;
    }
    if (col != mat[0].size() - 1) {
      mat[row][col + 1] ^= 1;
    }
  }
  bool zeroMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
      for (int col : row) {
        if (col != 0) {
          return false;
        }
      }
    }
    return true;
  }
  int minFlips(vector<vector<int>>& mat) { return minFlips(mat, 0, 0); }
  int minFlips(vector<vector<int>>& mat, int row, int col) {
    bool end(false);
    int nextRow(0), nextCol(0);
    if (col != mat[0].size() - 1) {
      nextRow = row;
      nextCol = col + 1;
    } else if (row != mat.size() - 1) {
      nextRow = row + 1;
      nextCol = 0;
    } else {
      end = true;
    }
    if (zeroMatrix(mat)) {
      return 0;
    } else if (!end) {
      int answer = minFlips(mat, nextRow, nextCol);
      if (answer >= 0) {
        return answer;
      }
    }
    flip(mat, row, col);
    if (zeroMatrix(mat)) {
      return 1;
    } else if (!end) {
      int answer = minFlips(mat, nextRow, nextCol);
      if (answer >= 0) {
        return answer + 1;
      }
    }
    flip(mat, row, col);
    return -1;
  }
};