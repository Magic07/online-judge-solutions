class Solution {
public:
    string longestPrefix(string s) {
      if(s.size()<=1){
        return "";
      }
      long hashp(0);
      long hashs(0);
      long baseOfS(1);
      int m(1e8+7);
      int maxLength(0);
      for(int i=0;i<s.size()-1;i++){
        hashp=(hashp*26+(s[i]-'a'))%m;
        hashs=(hashs+(s[s.size()-1-i]-'a')*baseOfS)%m;
        baseOfS=baseOfS*26%m;
        if(hashp==hashs){
          maxLength=i+1;
        }
      }
      return s.substr(0,maxLength);
    }
};