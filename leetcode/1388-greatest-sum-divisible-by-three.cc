class Solution {
 public:
  int maxSumDivThree(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 3 == 0) {
      return sum;
    }
    int r1[2] = {0};
    int r2[2] = {0};
    for (int i = 0; i < nums.size() && (r1[1] == 0 || r2[1] == 0); i++) {
      if (nums[i] % 3 == 1) {
        if (r1[0] == 0) {
          r1[0] = nums[i];
        } else if (r1[1] == 0) {
          r1[1] = nums[i];
        }
      }
      if (nums[i] % 3 == 2) {
        if (r2[0] == 0) {
          r2[0] = nums[i];
        } else if (r2[1] == 0) {
          r2[1] = nums[i];
        }
      }
    }
    if (sum % 3 == 1) {
      if (r1[0] != 0 && r2[1] != 0) {
        return sum - min(r1[0], r2[0] + r2[1]);
      } else if (r1[0] != 0) {
        return sum - r1[0];
      } else if (r2[1] != 0) {
        return sum - (r2[0] + r2[1]);
      } else {
        return 0;
      }
    } else if (sum % 3 == 2) {
      if (r2[0] != 0 && r1[1] != 0) {
        return sum - min(r2[0], r1[0] + r1[1]);
      } else if (r2[0] != 0) {
        return sum - r2[0];
      } else if (r1[1] != 0) {
        return sum - (r1[0] + r1[1]);
      } else {
        return 0;
      }
    }
    return 0;
  }
};