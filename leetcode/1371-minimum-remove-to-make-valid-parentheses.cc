class Solution {
public:
    string minRemoveToMakeValid(string s) {
      stringstream ss;
      int lp(0);
      for(char c:s){
        if(c==')'){
          if(lp>0){
            lp--;
          } else {
            continue;
          }
        }
        if(c=='('){
          lp++;
        }
        ss<<c;
      }
      string answer(ss.str());
      if(lp>0){
        for(int i=answer.size()-1;i>=0;i--){
          if(answer[i]=='('){
            answer.erase(i,1);
            lp--;
            if(lp==0){
              break;
            }
          }
        }
      }
      return answer;
    }
};