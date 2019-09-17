class Solution {
 public:
  int kConcatenationMaxSum(vector<int>& arr, int k) {
    long long singleSum = 0;
    long long singleMax = 0;
    int mod = 1e9 + 7;
    for (int e : arr) {
      singleSum += e;
    }
    // cout << "Single sum is " << singleSum << endl;
    long long sum = 0;
    for (int e : arr) {
      sum += e;
      if (sum < 0) {
        sum = 0;
      }
      singleMax = max(singleMax, sum);
    }
    if (k == 1) {
      return singleMax;
    } else {
      for (int e : arr) {
        sum += e;
        if (sum < 0) {
          sum = 0;
        }
        singleMax = max(singleMax, sum);
      }
    }
    // cout << "Single max is " << singleMax << endl;
    long long prefix = 0;
    long long prefixSum = 0;
    for (int i = arr.size() - 1; i >= 0; i--) {
      prefixSum += arr[i];
      prefix = max(prefix, prefixSum);
    }
    // cout << "Prefix is " << prefix << endl;
    long long suffix = 0;
    long long suffixSum = 0;
    for (int i = 0; i < arr.size(); i++) {
      suffixSum += arr[i];
      suffix = max(suffix, suffixSum);
    }
    // cout << "Suffix is " << suffix << endl;
    long long fullMax = prefix + singleSum * (k - 2) + suffix;
    long long answer = max(fullMax, singleMax);
    return answer % mod;
  }
};