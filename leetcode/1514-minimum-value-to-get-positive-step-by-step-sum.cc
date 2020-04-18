class Solution {
public:
    int minStartValue(vector<int>& nums) {
      int lowest(1);
      int currentSum(0);
      for(int num:nums){
        currentSum+=num;
        lowest=min(lowest, currentSum);
      }
      if(lowest>=0){
        return 1;
      }
      return abs(lowest)+1;
    }
};