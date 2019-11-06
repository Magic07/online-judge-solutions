class Solution {
 public:
  int minimumMoves(vector<int>& arr, int dp[100][100], int start, int end) {
    if (start >= end)
      return 1;
    if (dp[start][end] != 0)
      return dp[start][end];
    int answer = INT_MAX;
    for (int i = start; i < end; i++) {
      answer = min(answer, minimumMoves(arr, dp, start, i) +
                               minimumMoves(arr, dp, i + 1, end));
    }
    if (arr[start] == arr[end]) {
      answer = min(answer, minimumMoves(arr, dp, start + 1, end - 1));
    }
    dp[start][end]=answer;
    //cout<<"start="<<start<<", end="<<end<<", answer="<<answer<<endl;
    return answer;
  }
  int minimumMoves(vector<int>& arr) {
    int dp[100][100];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < arr.size(); i++) {
      dp[i][i] = 1;
    }
    return minimumMoves(arr, dp, 0, arr.size() - 1);
  }
};