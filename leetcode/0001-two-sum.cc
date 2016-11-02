class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;
    map<int, int> input;
    map<int, int>::iterator iter;
    for (int i = 0; i < numbers.size(); i++) {
      iter = input.find(target - numbers.at(i));
      if (iter != input.end()) {
        result.push_back(iter->second);
        result.push_back(i + 1);
        return result;
      }
      if (input.find(numbers.at(i)) == input.end()) {  // not found
        input.insert(std::pair<int, int>(numbers.at(i), i + 1));
      }
    }
  }
};