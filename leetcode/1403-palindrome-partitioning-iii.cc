class Solution {
public:
    int cost[100][100];
    int dp[100][100];
    void getCost(const string& s){
      memset(cost, 0, sizeof(cost));
      for(int i=0;i<s.size()-1;i++){
        cost[i][i+1]=s[i]==s[i+1]?0:1;
      }
      for(int i=2;i<s.size();i++){
        for(int j=0;j<s.size()-i;j++){
          cost[j][j+i]=s[j]==s[j+i]?cost[j+1][j+i-1]:cost[j+1][j+i-1]+1;
        }
      }
    }
    int palindromePartition(const string& s, int start, int k) {
      if(dp[start][k]!=INT_MAX){
        return dp[start][k];
      }
      int end=s.size()-1;
      if(k==1){
        dp[start][k]=cost[start][end];
        return cost[start][end];
      }
      if(k==end-start+1){
        dp[start][k]=0;
        return 0;
      }
      int answer(INT_MAX);
      for(int i=start+1;i<=end+2-k;i++){
        answer=min(answer, cost[start][i-1]+palindromePartition(s, i, k-1));
      }
      dp[start][k]=answer;
      return answer;
    }
    int palindromePartition(string s, int k) {
      getCost(s);
      memset(dp,0,sizeof(dp));
      for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
          dp[i][j]=INT_MAX;
        }
      }
      return palindromePartition(s, 0, k);
    }
};