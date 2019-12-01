class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
      int totalJumbo2=tomatoSlices-2*cheeseSlices;
      if(totalJumbo2%2==0){
        vector<int> answer={totalJumbo2/2, cheeseSlices-totalJumbo2/2};
        if(answer[0]<0||answer[1]<0){
          return vector<int>();
        }
        return answer;
      }
      return vector<int>();
    }
};