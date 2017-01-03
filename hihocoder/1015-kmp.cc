#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int* prefix(const string& pattern) {
  int* answer = (int*)malloc(pattern.size() * sizeof(int));
  memset(answer, 0, pattern.size() * sizeof(int));
  int k(0);
  for (int i = 1; i < pattern.size(); i++) {
    while (k > 0 && pattern.at(k) != pattern.at(i)) {
      k = answer[k - 1];
    }
    if (pattern.at(k) == pattern.at(i)) {
      k++;
    }
    answer[i] = k;
  }
  return answer;
}

int match(const string& text, const string& pattern) {
  int* pre = prefix(pattern);
  int pl(pattern.size()), q(0), answer(0);
  for (int i = 0; i < text.size(); i++) {
    while (q > 0 && pattern[q] != text[i]) {
      q = pre[q - 1];
    }
    if (pattern[q] == text[i]) {
      q++;
    }
    if (q == pl) {
      answer++;
      q = pre[q - 1];
    }
  }
  return answer;
}

int main() {
  int n(0);
  cin >> n;
  while (n > 0) {
    string pattern, text;
    cin >> pattern;
    cin >> text;
    cout << match(text, pattern) << endl;
    n--;
  }
}
