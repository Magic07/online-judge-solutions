class Solution {
 public:
  bool transformArrayInternal(vector<int>& arr) {
    bool changed(false);
    int lastDigit(arr[0]);
    for (int i = 1; i < arr.size() - 1; i++) {
      int lastDigitNew = arr[i];
      if (arr[i] < lastDigit && arr[i] < arr[i + 1]) {
        changed = true;
        arr[i]++;
      } else if (arr[i] > lastDigit && arr[i] > arr[i + 1]) {
        changed = true;
        arr[i]--;
      }
      lastDigit = lastDigitNew;
    }
    //cout<<changed<<endl;
    return changed;
  }
  vector<int> transformArray(vector<int>& arr) {
    if (arr.size() <= 2) {
      return arr;
    }
    while (transformArrayInternal(arr)) {
    }
    return arr;
  }
};