class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
      if(nums.size()==1&&nums[0]==1){
        return true;
      }
      if(nums.size()==1){
        return false;
      }
      int answer=gcd(nums[0], nums[1]);
      for(int i=1;i<nums.size();i++){
        answer=gcd(answer,nums[i]);
      }
      return answer==1;
    }
};