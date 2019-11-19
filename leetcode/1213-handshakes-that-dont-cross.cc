class Solution {
 public:
  long long dp[1001];
  int numberOfWays(int num_people) {
    memset(dp, 0, sizeof(dp));
    dp[2] = 1;
    for (int i = 4; i <= num_people; i += 2) {
      long long ways(0);
      ways += dp[i - 2] * 2;
      for (int j = 2; j < i - 2; j += 2) {
        long long addition = dp[j] * dp[i - 2 - j];
        ways += (addition % 1000000007);
      }
      dp[i] = ways % 1000000007;
    }
    return dp[num_people] % 1000000007;
  }
};