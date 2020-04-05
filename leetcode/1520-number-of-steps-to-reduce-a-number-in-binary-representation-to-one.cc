class Solution {
public:
    int numSteps(string s) {
      int steps(0);
      bool carry(false);
      for(int i=0;i<s.size()-1;i++){
        if(s[s.size()-i-1]=='1'){
          carry=true;
        } else {
          if(carry){
            steps++;
          }
        }
      }
      if(carry){
        steps++;
        return steps+s.size();
      } else {
        return s.size()-1;
      }
    }
};