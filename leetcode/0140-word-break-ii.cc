class Solution {
 private:
  vector<string> match(const string& s,
                       int start,
                       unordered_set<string>& wordDict,
                       bool* noMatch) {
    if (noMatch[start]) {
      return vector<string>();
    }
    vector<string> answer;
    for (int i = 1; i + start <= s.size(); i++) {
      string str = s.substr(start, i);
      if (wordDict.find(str) != wordDict.end()) {
        if (i + start == s.size()) {
          answer.push_back(str);
        } else {
          auto subAnswer = match(s, start + i, wordDict, noMatch);
          if (subAnswer.size() > 0) {
            for (auto a : subAnswer) {
              answer.push_back(str + " " + a);
            }
          }
        }
      }
    }
    if (answer.size() == 0) {
      noMatch[start] = true;
    }
    return answer;
  }

 public:
  vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    // An array indicates whether [index..end] has no solution. True means no
    // solution.
    bool* noMatch = (bool*)malloc(sizeof(bool) * s.size());
    memset(noMatch, 0, sizeof(bool) * s.size());
    return match(s, 0, wordDict, noMatch);
  }
};