class Solution {
public:
    unordered_map<int, int> dp;

    int numberOfArrays(const string& s, int start, int k){
      if(s.size()==start){
        return 1;
      }
      if(dp[start]!=0){
        return dp[start];
      }
      long long answer(0);
      for(int i=1;i<=s.size()-start;i++){
        long long current=stoll(s.substr(start,i));
        if(current<=k){
          if(start+i!=s.size()&&s[start+i]=='0'){
            continue;
          }
          answer+=numberOfArrays(s, start+i,k);
        } else {
          break;
        }
      }
      dp[start]=answer%1000000007;
      return answer%1000000007;
    }
    int numberOfArrays(string s, int k) {
      return numberOfArrays(s, 0,k);
    }
};