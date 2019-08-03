class Solution {
 public:
  // Change all 'O's not captured by 'X' to 'E'.
  void bfs(vector<vector<char>>& board, int i, int j) {
    if (board[i][j] != 'O') {
      return;
    }
    board[i][j] = 'E';
    if (i != 0) {
      bfs(board, i - 1, j);
    }
    if (i != board.size() - 1) {
      bfs(board, i + 1, j);
    }
    if (j != 0) {
      bfs(board, i, j - 1);
    }
    if (j != board[0].size() - 1) {
      bfs(board, i, j + 1);
    }
  }
  void convert(vector<vector<char>>& board, char before, char after) {
    for (vector<char>& row : board) {
      for (char& c : row) {
        if (c == before) {
          c = after;
        }
      }
    }
  }
  void solve(vector<vector<char>>& board) {
    if (board.size() == 0) {
      return;
    }
    for (int i = 0; i < board[0].size(); i++) {
      bfs(board, 0, i);
      bfs(board, board.size() - 1, i);
    }
    for (int j = 1; j < board.size() - 1; j++) {
      bfs(board, j, 0);
      bfs(board, j, board[0].size() - 1);
    }
    convert(board, 'O', 'X');
    convert(board, 'E', 'O');
  }
};