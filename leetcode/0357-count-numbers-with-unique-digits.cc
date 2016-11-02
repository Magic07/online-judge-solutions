class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
      return 1;
    } else if (n == 1) {
      return 10;
    } else if (n == 2) {
      return 91;
    } else if (n > 10) {
      return countNumbersWithUniqueDigits(10);
    } else {
      return countNumbersWithUniqueDigits(n - 1) + 9 * increment(n - 1);
    }
  }

  int increment(int n) {
    int result = 1;
    for (int i = 9; n > 0; i--, n--) {
      result *= i;
    }
    return result;
  }
};