#include <vector>

using namespace std;

class Solution {
 public:
  bool canFindSubsetForSum(vector<int>& nums,
                           vector<bool>& numUsed,
                           int start,
                           int sum,
                           int targetSum) {
    if (std::find(numUsed.begin(), numUsed.end(), false) == numUsed.end()) {
      return true;
    }
    if (start >= nums.size()) {
      return false;
    }
    for (int i = start; i < nums.size(); i++) {
      if (numUsed[i]) {
        continue;
      }
      if (nums[i] <= sum) {
        numUsed[i] = true;
        if (nums[i] == sum) {
          if (canFindSubsetForSum(nums, numUsed, 0, targetSum, targetSum)) {
            return true;
          } else {
            numUsed[i] = false;
          }
        } else {
          if (canFindSubsetForSum(nums, numUsed, i + 1, sum - nums[i],
                                  targetSum)) {
            return true;
          } else {
            numUsed[i] = false;
          }
        }
      }
    }
    return false;
  }
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    if (k > nums.size()) {
      return false;
    }
    vector<bool> numUsed(nums.size(), false);
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) {
      return false;
    }
    int subsetSum = sum / k;
    return canFindSubsetForSum(nums, numUsed, 0, subsetSum, subsetSum);
  }
};