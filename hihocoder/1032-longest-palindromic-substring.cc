#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

// Transform string to char array. Put '\n' at the begining of the array, insert
// '#' between each chars and append '\0' at the end of the array.
char* Preprocess(const string& input) {
  int length = 2 * input.size() + 1;
  char* input_chars = static_cast<char*>(malloc(length * sizeof(char)));
  memset(input_chars, 0, length * sizeof(char));
  input_chars[0] = '\n';
  for (int i = 0; i < input.size(); i++) {
    input_chars[2 * i + 1] = input[i];
    input_chars[2 * i + 2] = '#';
  }
  input_chars[length - 1] = '\0';
  return input_chars;
}

int* LengthArray(int size) {
  int* length_array = static_cast<int*>(malloc(size * sizeof(int)));
  memset(length_array, 0, size * sizeof(int));
  return length_array;
}

int LongestPalindrome(const string& input) {
  int length = 2 * input.size() + 1;
  int answer(0), center(0), right(0);
  char* ic = Preprocess(input);
  // Each item in |la| represents the longest length of ic[i]-centered
  // palindrome.
  int* la = LengthArray(length);
  la[0] = 0;
  for (int i = 1; i < length; i++) {
    // Get the minimal value of la[i].
    if (right > i)
      la[i] = min(la[2 * center - i], right - i);
    else
      la[i] = 1;
    // Try to increase la[i].
    while (ic[i + la[i]] == ic[i - la[i]])
      la[i]++;
    // Set |center| and |right|.
    if (la[i] + i > right) {
      right = la[i] + i;
      center = i;
    }
    if (ic[i + la[i] - 1] == '#')
      answer = max(answer, la[i] - 1);
    else
      answer = max(answer, la[i]);
  }
  free(ic);
  free(la);
  return answer;
}

int main() {
  int n(0);
  cin >> n;
  while (n > 0) {
    string input;
    cin >> input;
    cout << LongestPalindrome(input) << endl;
    n--;
  }
}

// Reference: http://articles.leetcode.com/longest-palindromic-substring-part-ii/
