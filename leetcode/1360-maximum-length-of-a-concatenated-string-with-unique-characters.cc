class Solution {
 public:
  vector<unordered_set<char>> setOfChar;
  int maxLength(vector<string>& arr,
                int start,
                int end,
                unordered_set<char> selected) {
    assert(start<=end);
    bool duplicated(false);
    for (char c : arr[start]) {
      if (selected.find(c) != selected.end()) {
        duplicated = true;
        break;
      }
    }
    if (start == end) {
      if (duplicated) {
        return selected.size();
      } else {
        return selected.size() + setOfChar[start].size();
      }
    }
    if (duplicated) {
      return maxLength(arr, start + 1, end, selected);
    } else {
      int max1 = maxLength(arr, start + 1, end, selected);
      selected.insert(setOfChar[start].begin(), setOfChar[start].end());
      int max2 = maxLength(arr, start + 1, end, selected);
      return max(max1, max2);
    }
  }
  int maxLength(vector<string>& arr) {
    if (arr.size() == 1) {
      return arr[0].size();
    }
    setOfChar=vector<unordered_set<char>>(arr.size());
    for (int i = 0; i < arr.size(); i++) {
      for (char c : arr[i]) {
        if (setOfChar[i].find(c) != setOfChar[i].end()) {
          setOfChar[i].clear();
          break;
        }
        setOfChar[i].insert(c);
      }
    }
    unordered_set<char> s;
    return maxLength(arr, 0, arr.size()-1, s);
  }
};