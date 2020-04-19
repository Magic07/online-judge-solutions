class Solution {
public:
  vector<int> minJumps;
  int jump(vector<int>& nums, int index){
    if(index==nums.size()-1){
      return 0;
    }
    if(minJumps[index]!=0){
      return minJumps[index];
    }
    if(nums[index]>=nums.size()-index-1){
      minJumps[index]=1;
      return 1;
    }
    int answer(INT_MAX-1);
    for(int i=nums[index];i>=1;i--){
      int nextJump=jump(nums, index+i);
      if(nextJump==1){
        minJumps[index]=2;
        return 2;
      }
      answer=min(answer, nextJump+1);
    }
    minJumps[index]=answer;
    return answer;
  }
  int jump(vector<int>& nums) {
    minJumps=vector<int>(nums.size());
    return jump(nums,0);
  }
};