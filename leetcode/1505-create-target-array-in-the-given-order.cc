class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
      vector<int> targets;
      for(int i=0;i<nums.size();i++){
        targets.insert(targets.begin()+index[i], nums[i]);
      }
      return targets;
    }
};