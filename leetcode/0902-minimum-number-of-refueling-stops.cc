class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> q;
    int answer(0);
    for (int i = 0; i < stations.size(); i++) {
      while (startFuel < stations[i][0]) {
        if (q.empty()) {
          return -1;
        }
        startFuel += q.top();
        q.pop();
        answer++;
      }
      q.push(stations[i][1]);
    }
    while (startFuel < target) {
      if (!q.empty()) {
        startFuel += q.top();
        q.pop();
        answer++;
      } else {
        return -1;
      }
    }
    return answer;
  }
};