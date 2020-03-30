class Solution {
public:
  vector<vector<vector<vector<int>>>> state;
  vector<int> getKmpNext(const string& evil){
    vector<int> next(evil.size()+1);
    int j=0;
    for(int i=1;i<evil.size();i++){
      while(j!=0&&evil[i]!=evil[j]){
        j=next[j-1];
      }
      if(evil[i]==evil[j]){
        j++;
      }
      next[i]=j;
    }
    return next;
  }
  
  int dp(int pos, int posEvil, bool equalToS1, bool equalToS2, const string& s1, const string& s2, const string& evil, const vector<int>& next){
    if(state[pos][posEvil][equalToS1][equalToS2]!=0){
      return state[pos][posEvil][equalToS1][equalToS2];
    }
    if(posEvil==evil.size()){
      return 0;
    }
    if(pos==s1.size()){
      return 1;
    }
    char start='a';
    char end='z';
    if(equalToS1){
      start=s1[pos];
    }
    if(equalToS2){
      end=s2[pos];
    }
    int answer(0);
    for(char c=start;c<=end;c++){
      int pe(posEvil);
      while(c!=evil[pe]&&pe!=0){
        pe=next[pe-1];
      }
      if(c==evil[pe]){
        pe++;
      }
      answer+=dp(pos+1, pe, equalToS1&&c==start, equalToS2&&c==end, s1,s2,evil,next);
      answer%=(int)(1e9+7);
    }
    state[pos][posEvil][equalToS1][equalToS2]=answer;
    return answer;
  }
  
  int findGoodStrings(int n, string s1, string s2, string evil) {
    vector<int> v(10,-1);
    state=vector(s1.size()+1, vector(evil.size()+1, vector(2, vector<int>(2))));
    vector<int> next=getKmpNext(evil);
    return dp(0,0,true, true, s1,s2,evil,next);
  }
};