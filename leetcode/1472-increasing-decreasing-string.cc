class Solution {
public:
    string sortString(string s) {
      int count[26];
      memset(count, 0, sizeof(count));
      for(char c: s){
        count[c-'a']++;
      }
      stringstream ss;
      while(ss.str().size()!=s.size()){
        for(int i=0;i<26;i++){
          if(count[i]>0){
            ss<<(char)(i+'a');
            count[i]--;
          }
        }
        for(int i=25;i>=0;i--){
          if(count[i]>0){
            ss<<(char)(i+'a');
            count[i]--;
          }
        }
      }
      return ss.str();
    }
};