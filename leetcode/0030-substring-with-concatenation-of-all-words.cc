// Please see "Discuss" section of this problem at leetcode.com to find a more
// efficient solution.

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> answer;
    if (words.size() == 0) {
      return answer;
    }
    int word_size = words[0].size();
    if (s.size() < words.size() * word_size) {
      return answer;
    }
    for (int i = 0; i <= s.size() - words.size() * word_size;
         i++) {  // Starting index of substrings.
      vector<bool> used = vector<bool>(words.size(), false);
      bool match(true);
      for (int j = 0; j < words.size(); j++) {  // Index of comparing string.
        bool found(false);
        for (int k = 0; k < words.size(); k++) {
          if (!used[k]) {
            if (s.compare(i + j * word_size, word_size, words[k]) == 0) {
              used[k] = true;
              found = true;
              break;
            }
          }
        }
        if (!found) {
          match = false;
          break;
        }
      }
      if (match) {
        answer.push_back(i);
      }
    }
    return answer;
  }
};
