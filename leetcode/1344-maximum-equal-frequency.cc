class Solution {
 public:
  bool checkEqualFrequency(
      const unordered_map<int, vector<int>>& ocurrenceNums) {
    if (ocurrenceNums.size() == 1) {  // All numbers occured only once.
      if (ocurrenceNums.find(1) != ocurrenceNums.end()) {
        return true;
      } else if (ocurrenceNums.begin()->second.size() == 1) {
        return true;
      }
      return false;
    }
    if (ocurrenceNums.size() != 2) {
      return false;
    }
    int numOnce = 0, numOnce2 = 0, numMutiple = 0;
    for (auto const& [key, val] : ocurrenceNums) {
      if (key == 1 && val.size() == 1) {
        return true;
      }
      if (val.size() == 1) {
        if (numOnce == 0) {
          numOnce = key;
        } else {
          numOnce2 = key;
        }
      } else {
        numMutiple = key;
      }
    }
    if (numOnce == numMutiple + 1) {
      return true;
    }
    if (numOnce2 != 0 && (numOnce == numOnce2 + 1 || numOnce == numOnce2 - 1)) {
      return true;
    }
    return false;
  }
  int maxEqualFreq(vector<int>& nums) {
    int NUM_MAX = 100001;
    int ocurrences[NUM_MAX];  // Index is the number, ocurrences[index] is the
                              // count of it occured.
    memset(ocurrences, 0, sizeof(ocurrences));
    for (int num : nums) {
      ocurrences[num]++;
    }
    unordered_map<int, vector<int>>
        ocurrenceNums;  // Key is the count of value occured.
    for (int i = 0; i < NUM_MAX; i++) {
      if (ocurrences[i] != 0) {
        ocurrenceNums[ocurrences[i]].push_back(i);
      }
    }
    if (checkEqualFrequency(ocurrenceNums)) {
      return nums.size();
    }
    for (int i = nums.size() - 1; i > 0; i--) {
      int num = nums[i];
      vector<int>& ocurrenceVector = ocurrenceNums[ocurrences[num]];
      if (ocurrenceVector.size() == 1) {
        ocurrenceNums.erase(ocurrences[num]);
      } else {
        auto numIt =
            std::find(ocurrenceVector.begin(), ocurrenceVector.end(), num);
        assert(numIt != ocurrenceVector.end());
        ocurrenceVector.erase(numIt);
      }
      ocurrences[num]--;
      if (ocurrences[num] != 0) {
        vector<int>& ocurrenceVectorToBePushed = ocurrenceNums[ocurrences[num]];
        ocurrenceVectorToBePushed.push_back(num);
      }
      if (checkEqualFrequency(ocurrenceNums)) {
        return i;
      }
    }
    return 1;
  }
};