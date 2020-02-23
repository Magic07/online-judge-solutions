class Solution {
public:
    vector<int> closestDivisorsForOneInteger(int num){
      double s = sqrt(num);
      int num1=ceil(s);
      int num2=num1;
      while(num1*num2!=num){
        if((num1*num2)>num){
          num1--;
          num2=num/num1;
        } else {
          num2++;
          num1=ceil((double)num/num2);
        }
      }
      return {num1, num2};
    }
    vector<int> closestDivisors(int num) {
      auto num1=closestDivisorsForOneInteger(num+1);
      auto num2=closestDivisorsForOneInteger(num+2);
      if(abs(num1[0]-num1[1])>abs(num2[0]-num2[1])){
        return num2;
      } else {
        return num1;
      }
    }
};