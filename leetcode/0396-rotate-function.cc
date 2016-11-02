class Solution {
 public:
  int maxRotateFunction(vector<int>& A) {
    if (A.size() == 0) {
      return 0;
    }
    int n = A.size();
    int sum = 0;
    int current = 0;
    for (int i = 0; i < n; i++) {
      current += A[i] * i;
      sum += A[i];
    }
    int result(current);
    for (int i = 1; i < n; i++) {
      current += sum;
      current -= n * A[n - i];
      if (current > result) {
        result = current;
      }
    }
    return result;
  }
};