class Solution {
  vector<vector<int>> answer;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      permute(nums,0);
      set<vector<int>> uniqueAnswers;
      for(auto& a:answer){
        uniqueAnswers.insert(a);
      }
      answer.assign(uniqueAnswers.begin(), uniqueAnswers.end());
      return answer;
    }
  
  void permute(vector<int>& nums, int start){
    if(start==nums.size()-1){
      answer.push_back(nums);
    }
    for(int i=start;i<nums.size();i++){
      if((i!=start)&&(nums[start]==nums[i])){
        continue;
      }
      swap(nums[start],nums[i]);
      permute(nums, start+1);
      swap(nums[start],nums[i]);
    }
  }
};