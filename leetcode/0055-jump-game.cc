#include <algorithm>

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int canReach(0);
    for (int i = 0; i < nums.size(); i++) {
      canReach = std::max(canReach, nums[i] + i);
      if (canReach >= nums.size() - 1) {
        return true;
      }
      if (canReach <= i) {
        return false;
      }
    }
    return false;
  }
};