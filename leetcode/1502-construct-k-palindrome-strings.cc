class Solution {
public:
    bool canConstruct(string s, int k) {
      if(s.size()<k) return false;
      if(s.size()==k) return true;
      int count[26];
      memset(count, 0, sizeof(count));
      for(const char c: s){
        count[c-'a']++;
      }
      int odd(0);
      for(int i=0;i<26;i++){
        if(count[i]%2){
          odd++;
        }
      }
      return odd<=k;
    }
};