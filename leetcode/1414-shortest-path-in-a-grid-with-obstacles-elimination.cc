#include <vector>

class Solution {
 public:
  bool visited[40][40][1600];
  int maxK;
  void addToQueue(vector<vector<int>>& grid,
                  queue<vector<int>>& remainMoves,
                  int row,
                  int col,
                  int k,
                  int moves) {
    // cout << "AddToQueue row=" << row << ", col=" << col << ", k=" << k <<
    // endl;
    for (int i = k; i <= maxK; i++) {
      if (visited[row][col][i]) {
        return;
      }
    }
    if (grid[row][col] == 1 && k == 0) {
      return;
    }
    if (grid[row][col] == 1)
      k--;
    // cout << "Push row=" << row << ", col=" << col << ", k=" << k << endl;
    remainMoves.push({row, col, k});
    visited[row][col][k] = true;
  }
  bool nextMove(vector<vector<int>>& grid,
                queue<vector<int>>& remainMoves,
                int moves) {
    vector<int> current = remainMoves.front();
    remainMoves.pop();
    int row = current[0];
    int col = current[1];
    int k = current[2];
    // cout << "row=" << row << ", col=" << col << endl;
    if (row == grid.size() - 1 && col == grid[0].size() - 1) {
      return true;
    }
    if (row != 0) {
      addToQueue(grid, remainMoves, row - 1, col, k, moves + 1);
    }
    if (row != grid.size() - 1) {
      addToQueue(grid, remainMoves, row + 1, col, k, moves + 1);
    }
    if (col != 0) {
      addToQueue(grid, remainMoves, row, col - 1, k, moves + 1);
    }
    if (col != grid[0].size() - 1) {
      addToQueue(grid, remainMoves, row, col + 1, k, moves + 1);
    }
    return false;
  }
  int shortestPath(vector<vector<int>>& grid, int k) {
    memset(visited, 0, sizeof(visited));
    queue<vector<int>> remainMoves;
    remainMoves.push({0, 0, k});
    int moves(0);
    maxK = k;
    while (!remainMoves.empty()) {
      int movesInThisRound = remainMoves.size();
      while (movesInThisRound > 0) {
        if (nextMove(grid, remainMoves, moves))
          return moves;
        movesInThisRound--;
      }
      moves++;
    }
    return -1;
  }
};