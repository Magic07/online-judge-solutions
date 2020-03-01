class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      vector<int> answers(nums.size());
      for(int i=0;i<nums.size();i++){
        int answer(0);
        for(int j=0;j<nums.size();j++){
          if(i!=j&&nums[j]<nums[i]){
            answer++;
          }
        }
        answers[i]=answer;
      }
      return answers;
    }
};