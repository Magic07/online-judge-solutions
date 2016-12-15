class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    int answer[m + 1][n + 1];
    memset(answer, 0, sizeof(int) * (m + 1) * (n + 1));
    for (int index = 0; index < strs.size(); index++) {
      string& str = strs[index];
      int m_needed(0);
      int n_needed(0);
      for (char ch : str) {
        if (ch == '0') {
          m_needed++;
        } else if (ch == '1') {
          n_needed++;
        }
      }
      for (int i = m; i >= m_needed; i--) {
        for (int j = n; j >= n_needed; j--) {
          answer[i][j] =
              max(answer[i][j], answer[i - m_needed][j - n_needed] + 1);
        }
      }
    }
    return answer[m][n];
  }
};