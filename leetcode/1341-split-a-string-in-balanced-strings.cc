class Solution {
public:
    int balancedStringSplit(string s) {
      int answer=0;
      int numberOfL=0;
      int numberOfR=0;
      for(const char& c:s){
        if(c=='R'){
          numberOfL++;
        } else {
          numberOfR++;
        }
        if(numberOfL==numberOfR){
          answer++;
          numberOfL=0;
          numberOfR=0;
        }
      }
      return answer;
    }
};