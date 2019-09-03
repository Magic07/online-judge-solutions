class Solution {
 public:
  int minCut(string s) {
    vector<int> dp(s.size() + 1, INT_MAX);
    dp[0] = -1;
    for (int i = 0; i < s.size(); i++) {
      for (int r = 0; i + r < s.size() && i - r >= 0 && s[i + r] == s[i - r];
           r++) {
        dp[i + r + 1] = min(dp[i + r + 1], 1 + dp[i - r]);
      }
      for (int r = 0;
           i + r + 1 < s.size() && i - r >= 0 && s[i + r + 1] == s[i - r];
           r++) {
        dp[i + r + 2] = min(dp[i + r + 2], 1 + dp[i - r]);
      }
    }
    return dp[s.size()];
  }
};

