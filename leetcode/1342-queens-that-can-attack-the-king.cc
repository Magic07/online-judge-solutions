class Solution {
 public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens,
                                          vector<int>& king) {
    int chess[8][8];  // 0 is empty, 1 is king, 2 is queen.
    vector<vector<int>> answer;
    memset(chess, 0, sizeof(chess));
    for (const auto& q : queens) {
      chess[q[0]][q[1]] = 2;
    }
    chess[king[0]][king[1]] = 1;
    for (int i = king[0]; i >= 0; i--) {
      if (chess[i][king[1]] == 2) {
        answer.push_back(vector<int>{i, king[1]});
        break;
      }
    }
    for (int i = king[0]+1; i <= 7; i++) {
      if (chess[i][king[1]] == 2) {
        answer.push_back(vector<int>{i, king[1]});
        break;
      }
    }
    for (int i = king[1]; i >= 0; i--) {
      if (chess[king[0]][i] == 2) {
        answer.push_back(vector<int>{king[0], i});
        break;
      }
    }
    for (int i = king[1]; i <= 7; i++) {
      if (chess[king[0]][i] == 2) {
        answer.push_back(vector<int>{king[0],i});
        break;
      }
    }
    int i = king[0];
    int j = king[1];
    while (i > 0 && j > 0) {
      i--;
      j--;
      if (chess[i][j] == 2) {
        answer.push_back(vector<int>{i, j});
        break;
      }
    }
    i = king[0];
    j = king[1];
    while (i < 7 && j < 7) {
      i++;
      j++;
      if (chess[i][j] == 2) {
        answer.push_back(vector<int>{i, j});
        break;
      }
    }
    i = king[0];
    j = king[1];
    while (i > 0 && j < 7) {
      i--;
      j++;
      if (chess[i][j] == 2) {
        answer.push_back(vector<int>{i, j});
        break;
      }
    }
    i = king[0];
    j = king[1];
    while (i < 7 && j > 0) {
      i++;
      j--;
      if (chess[i][j] == 2) {
        answer.push_back(vector<int>{i, j});
        break;
      }
    }
    return answer;
  }
};