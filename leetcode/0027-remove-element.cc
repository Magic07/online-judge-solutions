class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.size() == 0) {
      return 0;
    }
    int index1(0);
    int index2(nums.size() - 1);
    while (index1 <= index2) {
      if (nums[index1] == val) {
        std::swap(nums[index1], nums[index2]);
        index2--;
      } else {
        index1++;
      }
    }
    if (index2 == -1) {
      nums.clear();
    } else if (index2 < nums.size() - 1) {
      nums.erase(nums.begin() + index2 + 1, nums.end());
    }
    return nums.size();
  }
};