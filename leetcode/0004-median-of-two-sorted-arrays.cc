class Solution {
 private:
  // index starts from 1.
  double findNumberAtIndex(vector<int>& nums1, vector<int>& nums2, int index) {
    if (nums1.empty()) {
      return nums2[index - 1];
    }
    if (nums2.empty()) {
      return nums1[index - 1];
    }
    if (index == 1) {
      return min(nums1[0], nums2[0]);
    }
    int halfIndex = index / 2 - 1;
    int index1 = min(int(nums1.size() - 1), halfIndex);
    int index2 = min(int(nums2.size() - 1), halfIndex);
    if (nums1[index1] < nums2[index2]) {
      nums1.erase(nums1.begin(), nums1.begin() + index1 + 1);
      return findNumberAtIndex(nums1, nums2, index - index1 - 1);
    } else {
      nums2.erase(nums2.begin(), nums2.begin() + index2 + 1);
      return findNumberAtIndex(nums1, nums2, index - index2 - 1);
    }
  }

 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int length = nums1.size() + nums2.size();
    if (length % 2) {
      return findNumberAtIndex(nums1, nums2, length / 2 + 1);
    } else {
      // Deep copy nums1 and nums2 because findNumberAtIndex will modify nums1
      // and nums2.
      vector<int> nums3 = nums1;
      vector<int> nums4 = nums2;
      return (findNumberAtIndex(nums1, nums2, length / 2) +
              findNumberAtIndex(nums3, nums4, length / 2 + 1)) /
             2;
    }
  }
};