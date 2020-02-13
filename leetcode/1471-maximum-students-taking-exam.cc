#include <vector>

class Solution {
 public:
  string toBitmask(int decimal) {
    stringstream ss;
    int mask = 256;
    while (mask > 0) {
      cout << ((decimal & mask) ? 1 : 0);
      mask = mask >> 1;
    }
    return ss.str();
  }
  int maxStudents(vector<vector<char>>& seats) {
    int sizeOfRow = seats.size();
    int sizeOfCol = seats[0].size();
    int goodSeats[8];
    for (int i = 0; i < sizeOfRow; i++) {
      int mask(0);
      for (int j = 0; j < sizeOfCol; j++) {
        if (seats[i][j] == '.') {
          mask += (1 << j);
        }
      }
      goodSeats[i] = mask;
    }
    int maxStudents[8][1 << 8];
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < (1 << 8); j++) {
        maxStudents[i][j] = -1;
      }
    }
    for (int j = 0; j < (1 << sizeOfCol); j++) {
      if ((j & goodSeats[0]) != j)
        continue;
      if (j & (j >> 1))
        continue;
      maxStudents[0][j] = __builtin_popcount(j);
    }
    cout << maxStudents[0][0] << endl;
    for (int currentRow = 1; currentRow < sizeOfRow; currentRow++) {
      for (int currentSeats = 0; currentSeats < (1 << sizeOfCol);
           currentSeats++) {
        if ((currentSeats & goodSeats[currentRow]) != currentSeats)
          continue;
        if (currentSeats & (currentSeats >> 1))
          continue;
        for (int previousSeats = 0; previousSeats < (1 << sizeOfCol);
             previousSeats++) {
          if (maxStudents[currentRow - 1][previousSeats] < 0)
            continue;
          if (currentSeats & (previousSeats >> 1))
            continue;
          if ((currentSeats >> 1) & previousSeats)
            continue;
          maxStudents[currentRow][currentSeats] =
              max(maxStudents[currentRow][currentSeats],
                  maxStudents[currentRow - 1][previousSeats] +
                      __builtin_popcount(currentSeats));
        }
      }
    }
    int answer(0);
    for (int j = 0; j < sizeOfRow; j++) {
      for (int i = 0; i < (1 << sizeOfCol); i++) {
        answer = max(answer, maxStudents[j][i]);
      }
    }
    return answer;
  }
};