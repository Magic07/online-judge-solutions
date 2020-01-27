#include <algorithm>
#include <vector>

class Solution {
 public:
  int dp[300][11];
  int minDifficulty(int start, vector<int>& jobDifficulty, int d) {
    if (dp[start][d] != 0)
      return dp[start][d];
    if (d == 1) {
      return *max_element(jobDifficulty.begin() + start, jobDifficulty.end());
    }
    int answer(INT_MAX);
    for (int i = start; i <= jobDifficulty.size() - d; i++) {
      answer = min(answer, *max_element(jobDifficulty.begin() + start,
                                        jobDifficulty.begin() + i + 1) +
                               minDifficulty(i + 1, jobDifficulty, d - 1));
    }
    dp[start][d] = answer;
    return answer;
  }
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    memset(dp, 0, sizeof(dp));
    if (jobDifficulty.size() < d)
      return -1;
    return minDifficulty(0, jobDifficulty, d);
  }
};