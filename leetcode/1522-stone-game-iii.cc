class Solution {
 public:
  int dp[50003];
  string stoneGameIII(vector<int>& stoneValue) {
    memset(dp, 0, sizeof(dp));
    for(int i=stoneValue.size()-1;i>=0;i--){
      dp[i]=stoneValue[i]-dp[i+1];
      int extraStoneValue(0);
      for(int j=1;j<3&&i+j<stoneValue.size();j++){
        extraStoneValue+=stoneValue[i+j];
        dp[i]=max(dp[i], stoneValue[i]+extraStoneValue-dp[i+j+1]);
      }
    }
    if (dp[0] > 0) {
      return "Alice";
    } else if (dp[0] < 0) {
      return "Bob";
    } else {
      return "Tie";
    }
  }
};