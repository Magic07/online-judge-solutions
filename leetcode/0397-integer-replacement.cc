class Solution {
 public:
  unordered_map<int, int> replacementsNeeded;
  int integerReplacement(int n) {
    if (n == 1) {
      return 0;
    }
    if(n==INT_MAX){
      return 32;
    }
    if (replacementsNeeded.find(n) != replacementsNeeded.end()) {
      return replacementsNeeded[n];
    }
    if (n % 2 == 0) {
      replacementsNeeded[n] = integerReplacement(n / 2) + 1;
    } else {
      replacementsNeeded[n] =
          min(integerReplacement(n + 1), integerReplacement(n - 1)) + 1;
    }
    return replacementsNeeded[n];
  }
};