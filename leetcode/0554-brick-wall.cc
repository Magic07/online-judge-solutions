class Solution {
 public:
  bool onlyOneBrick(vector<vector<int>>& wall) {
    for (const vector<int>& row : wall) {
      if (row.size() != 1) {
        return false;
      }
    }
    return true;
  }
  int leastBricks(vector<vector<int>>& wall) {
    if (onlyOneBrick(wall)) {
      return wall.size();
    }
    int width = 0;
    for (int w : wall[0]) {
      width += w;
    }
    unordered_map<int, int> cut;
    for (const auto& row : wall) {
      int length = 0;
      for (int brick : row) {
        length += brick;
        if (length == width) {
          break;
        }
        if (cut.find(length) == cut.end()) {
          cut[length] = 0;
        }
        cut[length]++;
      }
    }
    auto it = std::max_element(
        cut.begin(), cut.end(),
        [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
          return lhs.second < rhs.second;
        });
    int maxCut = it->second;
    return wall.size() - maxCut;
  }
};