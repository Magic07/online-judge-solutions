#include <algorithm>
#include <iostream>

using namespace std;

int Triangle(int height, int data[][1000]) {
  for (int i = 0; i <= height; i++) {
    if (i == height) {  // All input data is processed.
      int answer(0);
      for (int line_index = 0; line_index < height; line_index++) {
        answer = max(answer, data[height - 1][line_index]);
      }
      return answer;
    } else if (i == 0) {  // Skip the first line.
      continue;
    } else {
      data[i][0] = data[i - 1][0] + data[i][0];
      data[i][i] = data[i - 1][i - 1] + data[i][i];
      for (int line_index = 1; line_index < i; line_index++) {
        data[i][line_index] =
            max(data[i - 1][line_index - 1], data[i - 1][line_index]) +
            data[i][line_index];
      }
    }
  }
}

int main() {
  int height(0);
  cin >> height;
  int data[100][1000];
  for (int i = 0; i < height; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> data[i][j];
    }
  }
  cout << Triangle(height, data);
}
