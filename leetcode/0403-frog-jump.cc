class Solution {
  // Whether the ith stone can cross when its previous stone is j.
  // 0 - not computed, 1 - cannot cross, 2 - can cross.
  int success[1100][1100];

 public:
  bool canCross(vector<int>& stones) {
    memset(success, 0, sizeof(success));
    return canCross(stones, 0, 0);
  }

  bool canCross(vector<int>& stones, int pre, int current) {
    if (success[current][pre] != 0) {
      if(success[current][pre]==1){
        return false;
      } else {
        return true;
      }
    }
    if(current==stones.size()-1){
      return true;
    }
    int lastSteps = stones[current] - stones[pre];
    vector<int> nextPossibleStones;
    for (int i = current+1;
         i < stones.size() && stones[i] - stones[current] <= lastSteps + 1;
         i++) {
      if (stones[i] - stones[current] >= lastSteps - 1 &&
          stones[i] - stones[current] <= lastSteps + 1) {
        nextPossibleStones.push_back(i);
      }
    }
    for (int next : nextPossibleStones) {
      if (canCross(stones, current, next)) {
        success[current][pre] = 2;
        return true;
      }
    }
    success[current][pre] = 1;
    return false;
  }
};