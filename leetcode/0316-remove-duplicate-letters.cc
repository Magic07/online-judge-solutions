#include <iostream>
#include <array>
#include <stack>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Solution {
 public:
  string removeDuplicateLetters(string s) {
    array<int, 26> count = {0};
    array<bool, 26> exist = {false};
    stack<char> answer;
    for (auto c : s) {
      count[c - 'a']++;
    }
    for (auto c : s) {
      auto c_index(c - 'a');
      while (!answer.empty() && answer.top() > c &&
             count[answer.top() - 'a'] > 0 && !exist[c_index]) {
        exist[answer.top() - 'a'] = false;
        answer.pop();
      }
      count[c_index]--;
      if (!exist[c_index]) {
        answer.push(c);
        exist[c_index] = true;
      }
    }
    string str("");
    while (!answer.empty()) {
      str = answer.top() + str;
      answer.pop();
    }
    return str;
  }
};