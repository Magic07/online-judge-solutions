class Solution {
 public:
  int distinctEchoSubstrings(string t) {
    set<string_view> answer;
    string_view text(t);
    for (int interval = 1; interval <= text.size() / 2; interval++) {
      for (int i = 0; i <= text.size() - interval; i++) {
        if (text.substr(i, interval) == text.substr(i + interval, interval)) {
          answer.insert(text.substr(i, 2*interval));
        }
      }
    }
    return answer.size();
  }
};