class Solution {
 public:
  int countPrimes(int n) {
    if (n < 3)
      return 0;
    bool number[n / 2];
    memset(number, 0, n * sizeof(bool) / 2);
    int primeNumbers = n / 2;
    int index = 0;
    for (int i = 3; i <= sqrt(n); i += 2) {
      if (number[i / 2] == 1)
        continue;
      int m = 3;
      while (i * m < n) {
        index = i * m / 2;
        if (number[index] == 0) {
          number[index] = 1;
          primeNumbers--;
        }
        m += 2;
      }
    }
    return primeNumbers;
  }
};