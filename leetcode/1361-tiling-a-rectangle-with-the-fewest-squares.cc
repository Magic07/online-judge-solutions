class Solution {
 public:
  int skyline[13];
  int globalAnswer=INT_MAX;

  inline int lowestCol(int width) {
    int lowest(0);
    for (int i = 0; i < width; i++) {
      if (skyline[i] < skyline[lowest]) {
        lowest = i;
      }
    }
    return lowest;
  }

  inline int largestSideLength(int start, int maxHeight, int maxWidth) {
    int maxPossible = min(maxHeight - skyline[start], maxWidth - start);
    for (int i = 1; i < maxPossible; i++) {
      if (skyline[start + i] != skyline[start]) {
        return i - 1;
      }
    }
    return maxPossible;
  }

  inline void fill(int start, int sideLength) {
    for (int i = start; i < start + sideLength; i++) {
      skyline[i] += sideLength;
    }
  }

  inline void undoFill(int start, int sideLength) {
    for (int i = start; i < start + sideLength; i++) {
      skyline[i] -= sideLength;
    }
  }

  int tryFill(int n, int m, int squares) {
    int lowestIndex = lowestCol(m);
    if (skyline[lowestIndex] == n) {
      globalAnswer=min(globalAnswer,squares);
      return 0;
    } else if (squares >= globalAnswer) {
      return INT_MAX / 2;
    } else {
      int answer = INT_MAX / 2;
      int lengthTry = largestSideLength(lowestIndex, n, m);
      for (int i = lengthTry; i > 0; i--) {
        fill(lowestIndex, i);
        answer = min(answer, tryFill(n, m, squares+1) + 1);
        undoFill(lowestIndex, i);
        if (answer == 1) {
          continue;
        }
      }
      return answer;
    }
  }

  int tilingRectangle(int n, int m) {
    memset(skyline, 0, sizeof(skyline));
    return tryFill(n, m, 0);
  }
};