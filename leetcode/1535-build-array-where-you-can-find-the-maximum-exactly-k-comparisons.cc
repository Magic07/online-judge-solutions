class Solution {
 public:
  unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int,int>>>> dp;
  int numOfArrays(int n, int l, int m, int k) {
    if (m - l < k) {
      return 0;
    }
    if (n < k) {
      return 0;
    }
    if (n == 0 && k == 0) {
      return 1;
    } else if (n == 0) {
      return 0;
    }
    if(dp[n][l][m][k]!=0){
      return dp[n][l][m][k];
    }
    long long answer(0);
    answer += (long long)numOfArrays(n - 1, l, m, k)*l;
    if (k == 0) {
      answer=answer%1000000007;
      dp[n][l][m][k]=answer;
      return answer;
    }
    int current=l+1;
    while (current <= m) {
      answer += numOfArrays(n - 1, current, m, k - 1);
      current++;
    }
    answer=answer%1000000007;
    dp[n][l][m][k]=answer;
    return answer;
  }
  int numOfArrays(int n, int m, int k) { return numOfArrays(n, 0, m, k); }
};