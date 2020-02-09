#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  unordered_map<int, vector<int>> indices;
  int bfs(vector<int>& arr) {
    int steps(0);
    vector<bool> visited(arr.size());
    queue<int> thisRound;
    queue<int> nextRound;
    thisRound.push(0);
    while (!thisRound.empty()) {
      while (!thisRound.empty()) {
        int current(thisRound.front());
        thisRound.pop();
        if (visited[current]) {
          continue;
        }
        if (current == arr.size() - 1) {
          return steps;
        }
        visited[current] = true;
        if (current != 0) {
          nextRound.push(current - 1);
        }
        nextRound.push(current + 1);
        for (int i : indices[arr[current]]) {
          if (i != current) {
            nextRound.push(i);
          }
        }
      }
      thisRound = nextRound;
      queue<int> empty;
      swap(nextRound, empty);
      steps++;
    }
    return -1;
  }
  int minJumps(vector<int>& arr) {
    if (arr.size() == 1) {
      return 0;
    }
    vector<pair<int, int>> toBeDeleted;
    int lastValue(arr[0]);
    int lastIndex(0);
    for (int i = 1; i < arr.size(); i++) {
      if (lastValue != arr[i]) {
        if (i - lastIndex > 5) {
          toBeDeleted.push_back(pair<int, int>(lastIndex + 1, i - 2));
        }
        lastValue = arr[i];
        lastIndex = i;
      }
    }
    for (int i = toBeDeleted.size() - 1; i >= 0; i--) {
      arr.erase(arr.begin() + toBeDeleted[i].first,
                arr.begin() + toBeDeleted[i].second);
    }
    for (int i = 0; i < arr.size(); i++) {
      indices[arr[i]].push_back(i);
    }
    return bfs(arr);
  }
};