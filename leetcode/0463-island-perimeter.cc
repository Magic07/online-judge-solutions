class Solution {
 private:
  int perimeter(int row, int col, vector<vector<int>>& grid) {
    if (grid[row][col] == 0)
      return 0;
    int p(0);
    if (row == 0 || grid[row - 1][col] == 0)
      p++;
    if (col == 0 || grid[row][col - 1] == 0)
      p++;
    if (row == grid.size() - 1 || grid[row + 1][col] == 0)
      p++;
    if (col == grid[0].size() - 1 || grid[row][col + 1] == 0)
      p++;
    return p;
  }

 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    if (grid.size() == 0)
      return 0;
    int answer(0);
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        answer += perimeter(i, j, grid);
      }
    }
    return answer;
  }
};