class Solution {
public:
  unordered_map<int, unordered_map<int, int>> dp;
  vector<int> possibleWays;
  unordered_map<int, vector<int>> next;
  void fillPossibleWays(){
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(j==i) continue;
        for(int k=0;k<3;k++){
          if(k==j) continue;
          possibleWays.push_back(i*100+j*10+k);
        }
      }
    }
  }
  void fillNext(){
    next[0]=possibleWays;
    for(int p: possibleWays){
      for(int nextP:possibleWays){
        if(nextP%10==p%10) continue;
        int tempP(p/10);
        int tempNextP(nextP/10);
        if(tempP%10==tempNextP%10) continue;
        tempP/=10;
        tempNextP/=10;
        if(tempP%10==tempNextP%10) continue;
        next[p].push_back(nextP);
      }
    }
  }
  int numOfWays(int last, int n){
    if(n==0){
      return 1;
    }
    if(dp[last][n]!=0){
      return dp[last][n];
    }
    long long answer(0);
    for(int p: next[last]){
      answer+=numOfWays(p,n-1);
    }
    answer=answer%(long long)(1e9+7);
    dp[last][n]=answer;
    return answer;
  }
  int numOfWays(int n) {
    fillPossibleWays();
    fillNext();
    return numOfWays(0,n);
  }
};