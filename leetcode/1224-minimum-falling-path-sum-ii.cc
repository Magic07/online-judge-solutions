class Solution {
 public:
  int dp[200][200];
  int path(const vector<vector<int>>& arr, int row, int lastCol, int sum) {
    if (row == arr.size()) {
      return sum;
    }
    int answer(INT_MAX);
    for (int i = 0; i < arr[0].size(); i++) {
      if (i == lastCol)
        continue;
      int tempAnswer = INT_MAX;
      if (dp[row][i] != 0) {
        tempAnswer = dp[row][i] + sum;
      } else {
        tempAnswer = path(arr, row + 1, i, sum + arr[row][i]);
        dp[row][i] = tempAnswer - sum;
      }
      answer = min(answer, tempAnswer);
    }
    return answer;
  }
  int minFallingPathSum(vector<vector<int>>& arr) {
    memset(dp, 0, sizeof(dp));
    return path(arr, 0, -1, 0);
  }
};