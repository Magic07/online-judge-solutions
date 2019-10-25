class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> lastPos;
    for (int i = 0; i < nums.size(); i++) {
      if (lastPos.find(nums[i]) != lastPos.end() &&
          (i - lastPos[nums[i]] <= k)) {
        return true;
      } else {
        lastPos[nums[i]] = i;
      }
    }
    return false;
  }
};