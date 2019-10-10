#include <string>

using namespace std;

class Solution {
 public:
  int calulateDp(const string& s, int dp[100][100], int start, int end) {
    if (dp[start][end] != 0) {
      return dp[start][end];
    }
    if (start == end) {
      dp[start][start] = 1;
      return 1;
    } else {
      int c[3] = {INT_MAX, INT_MAX, INT_MAX};
      if (s[end] == s[start] || s[end] == s[end - 1]) {
        c[0] = calulateDp(s, dp, start, end - 1);
      } else if (s[start] == s[start + 1] || s[start] == s[end]) {
        c[1] = calulateDp(s, dp, start + 1, end);
      } else {
        for (int i = start; i < end; i++) {
          c[2] = min(c[2], calulateDp(s, dp, start, i) +
                               calulateDp(s, dp, i + 1, end));
        }
      }
      dp[start][end] = *std::min_element(c, c + 3);
      return dp[start][end];
    }
  }

  int strangePrinter(string s) {
    if (s.size() == 0) {
      return 0;
    }
    int dp[100][100];
    memset(dp, 0, sizeof(dp));
    return calulateDp(s, dp, 0, s.size() - 1);
  }
};