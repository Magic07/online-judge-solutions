class Solution {
 public:
  bool match(const string& s,
             int start,
             unordered_set<string>& wordDict,
             bool* noMatch) {
    if (noMatch[start]) {
      return false;
    }
    for (int i = 1; i + start <= s.size(); i++) {
      if (wordDict.find(s.substr(start, i)) != wordDict.end()) {
        if (i + start == s.size() || match(s, start + i, wordDict, noMatch)) {
          return true;
        }
      }
    }
    noMatch[start] = true;
    return false;
  }
  bool wordBreak(string s, unordered_set<string>& wordDict) {
    // An array indicates whether [index..end] has no solution. True means no
    // solution.
    bool* noMatch = (bool*)malloc(sizeof(bool) * s.size());
    memset(noMatch, 0, sizeof(bool) * s.size());
    return match(s, 0, wordDict, noMatch);
  }
};