class Solution {
public:
  string reverse(string s, int begin, int end){
    stringstream ss;
    for(int i=0;i<begin;i++){
      ss<<s[i];
    }
    for(int i=end-1;i>begin;i--){
      ss<<s[i];
    }
    for(int i=end+1;i<s.size();i++){
      ss<<s[i];
    }
    return ss.str();
  }
    string reverseParentheses(string s) {
      while(true){
        int lastLeft=0;
        for(int i=0;i<s.size();i++){
          if(s[i]=='('){
            lastLeft=i;
          } else if(s[i]==')'){
            s=reverse(s,lastLeft,i);
            break;
          } else if(i==s.size()-1){
            return s;
          }
        }
      }
    }
};