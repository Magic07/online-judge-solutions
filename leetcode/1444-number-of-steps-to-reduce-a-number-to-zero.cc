class Solution {
public:
    int numberOfSteps (int num) {
      int answer(0);
      while(num!=0){
        if(num%2){
          num--;
        } else {
          num/=2;
        }
        answer++;
      }
      return answer;
    }
};