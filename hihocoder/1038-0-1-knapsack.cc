#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int Knapsack(int number, int max_size, int data[][2]) {
  int* answer = (int*)malloc(max_size * sizeof(int));
  memset(answer, 0, max_size * sizeof(int));
  for (int i = 0; i < number; i++) {
    for (int j = max_size - 1; j > data[i][0]; j--) {
      answer[j] = max(answer[j], answer[j - data[i][0]] + data[i][1]);
    }
  }
  return answer[max_size - 1];
}

int main() {
  int number(0), max_size(0);
  cin >> number >> max_size;
  int data[500][2];
  for (int i = 0; i < number; i++) {
    cin >> data[i][0] >> data[i][1];
  }
  cout << Knapsack(number, max_size, data);
}
