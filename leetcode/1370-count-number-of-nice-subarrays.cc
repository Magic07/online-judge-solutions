class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      vector<int> oddPos;
      for(int i=0;i<nums.size();i++){
        if(nums[i]%2){
          oddPos.push_back(i);
        }
      }
      if(oddPos.size()<k){
        return 0;
      }
      int answer(0);
      for(int i=0;i<oddPos.size()-k+1;i++){
        int left=i==0?oddPos[i]+1:oddPos[i]-oddPos[i-1];
        int right=(i+k-1)==oddPos.size()-1?nums.size()-oddPos[i+k-1]:oddPos[i+k]-oddPos[i+k-1];
        answer+=left*right;
      }
      return answer;
    }
};