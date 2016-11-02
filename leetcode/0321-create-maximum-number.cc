class Solution {
 public:
  vector<int> maxNumber(vector<int>& nums, int k) {
    if (k == 0) {
      return vector<int>(0);
    }
    vector<int> result = nums;
    for (int n = result.size(); n > k; n--) {
      bool deleted(false);
      int i = 0;
      for (i = 0; i < result.size() - 1; i++) {
        if (result[i] < result[i + 1]) {
          result.erase(result.begin() + i);
          deleted = true;
          break;
        }
      }
      if (!deleted) {
        result.erase(result.begin() + result.size() - 1);
      }
    }
    return result;
  }

  vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    auto i1 = nums1.begin(), i2 = nums2.begin();
    while (i1 != nums1.end() && i2 != nums2.end()) {
      if (*i1 > *i2) {
        result.push_back(*i1);
        i1++;
      } else if (*i1 < *i2) {
        result.push_back(*i2);
        i2++;
      } else {  // Equal
        auto t1 = i1, t2 = i2;
        while (*t1 == *t2 && t1 != nums1.end() && t2 != nums2.end()) {
          t1++;
          t2++;
        }
        if (t1 == nums1.end() || t2 == nums2.end()) {
          if (t1 == nums1.end()) {
            result.push_back(*i2);
            i2++;
          } else {
            result.push_back(*i1);
            i1++;
          }
        } else if (*t1 > *t2) {
          result.push_back(*i1);
          i1++;
        } else {
          result.push_back(*i2);
          i2++;
        }
      }
    }
    while (i1 != nums1.end()) {
      result.push_back(*i1);
      i1++;
    }
    while (i2 != nums2.end()) {
      result.push_back(*i2);
      i2++;
    }
    return result;
  }

  // Return true if nums1 > nums2, else return false (nums1 <= nums2)
  bool compare(vector<int>& nums1, vector<int>& nums2) {
    auto i1 = nums1.begin(), i2 = nums2.begin();
    while (i1 != nums1.end()) {
      if (*i1 > *i2) {
        return true;
      } else if (*i1 < *i2) {
        return false;
      }
      i1++;
      i2++;
    }
    return false;
  }

  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> max(k, -1);
    if (k == 0) {
      return max;
    }
    if (nums1.size() == 0) {
      return maxNumber(nums2, k);
    }
    if (nums2.size() == 0) {
      return maxNumber(nums1, k);
    }
    for (int i = std::max(0, k - (int)(nums2.size()));
         i <= std::min(k, (int)nums1.size()); i++) {
      auto v1 = maxNumber(nums1, i);
      auto v2 = maxNumber(nums2, k - i);
      auto v = merge(v1, v2);
      if (compare(v, max)) {
        max = v;
      }
    }
    return max;
  }
};