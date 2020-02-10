#include <vector>

class Solution {
 public:
  bool visited[2020][4];
  void positionsOfSbt(vector<vector<char>>& grid, int& s, int& b, int& t) {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 'B') {
          b = i * 100 + j;
        } else if (grid[i][j] == 'S') {
          s = i * 100 + j;
        } else if (grid[i][j] == 'T') {
          t = i * 100 + j;
        }
      }
    }
  }
  bool isValidPositionForPlayer(int player,
                                int box,
                                const vector<vector<char>>& grid,
                                bool visited[2020]) {
    if (!isValidCoordinator(player, grid)) {
      return false;
    }
    if (player == box) {
      return false;
    }
    const char cell = grid[player / 100][player % 100];
    if (cell == '#') {
      return false;
    }
    if (visited[player]) {
      return false;
    }
    return true;
  }
  bool isValidCoordinator(int pos, const vector<vector<char>>& grid) {
    if (pos < 0 || pos / 100 >= grid.size() || pos % 100 >= grid[0].size()) {
      return false;
    }
    return true;
  }
  vector<int> possiblePushDirections(vector<vector<char>>& grid,
                                     int player,
                                     int box) {
    assert(player<2020);
    assert(box<2020);
    vector<int> directions;
    if (!isValidCoordinator(box, grid)) {
      return directions;
    }
    if (grid[box / 100][box % 100] == '#') {
      return directions;
    }
    bool visited[2020];
    memset(visited, 0, sizeof(visited));
    // if (!isValidPositionForPlayer(player, box, grid, visited))
    //   return directions;
    queue<int> toBeVisited;
    toBeVisited.push(player);
    while (!toBeVisited.empty()) {
      auto currentPlayer = toBeVisited.front();
      toBeVisited.pop();
      if (visited[currentPlayer])
        continue;
      visited[currentPlayer] = true;
      if (currentPlayer == box - 100) {
        directions.push_back(180);
      }
      if (currentPlayer == box + 100) {
        directions.push_back(0);
      }
      if (currentPlayer == box - 1) {
        directions.push_back(90);
      }
      if (currentPlayer == box + 1) {
        directions.push_back(270);
      }
      if (directions.size() == 4) {
        return directions;
      }
      if (isValidPositionForPlayer(currentPlayer - 100, box, grid, visited)) {
        toBeVisited.push(currentPlayer - 100);
      }
      if (isValidPositionForPlayer(currentPlayer + 100, box, grid, visited)) {
        toBeVisited.push(currentPlayer + 100);
      }
      if (isValidPositionForPlayer(currentPlayer - 1, box, grid, visited)) {
        toBeVisited.push(currentPlayer - 1);
      }
      if (isValidPositionForPlayer(currentPlayer + 1, box, grid, visited)) {
        toBeVisited.push(currentPlayer + 1);
      }
    }
    return directions;
  }
  int pushedPosition(int origin, int direction) {
    if (direction == 0) {
      return origin - 100;
    } else if (direction == 90) {
      return origin + 1;
    } else if (direction == 180) {
      return origin + 100;
    } else if (direction == 270) {
      return origin - 1;
    }
    return origin;
  }
  int minPushBox(vector<vector<char>>& grid) {
    memset(visited, 0, sizeof(visited));
    int s = 0, b = 0, t = 0;
    positionsOfSbt(grid, s, b, t);
    set<int> currentRound;
    set<int> nextRound;

    vector<int> possibleDirections = possiblePushDirections(grid, s, b);
    for (int d : possibleDirections) {
      if (!visited[b][d / 90]) {
        currentRound.insert(d * 10000 + b);
      }
    }
    int steps(0);
    while (!currentRound.empty()) {
      for (auto it = currentRound.begin(); it != currentRound.end(); it++) {
        int p = *it;
        visited[p % 10000][p / 10000 / 90] = true;
        if (p % 10000 == t) {
          return steps;
        }
        int oldBoxPosition = p%10000;
        int newBoxPosition = pushedPosition(oldBoxPosition, p / 10000);
        if (newBoxPosition == t) {
          return steps + 1;
        }
        vector<int> pds =
            possiblePushDirections(grid, oldBoxPosition, newBoxPosition);
        for (int d : pds) {
          if (!visited[newBoxPosition][d / 90]) {
            nextRound.insert(d*10000+newBoxPosition);
          }
        }
      }
      currentRound = nextRound;
      nextRound.clear();
      steps++;
    }
    return -1;
  }
};