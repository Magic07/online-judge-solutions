#include <string>

class Solution {
 public:
  vector<string> answer;
  struct Expression {
    size_t start;
    size_t end;
    long sum;
    long lastNum;
    string output;
    Expression(size_t startIn,
               size_t endIn,
               long sumIn,
               long lastNumIn,
               string outputIn)
        : start(startIn),
          end(endIn),
          sum(sumIn),
          lastNum(lastNumIn),
          output(outputIn) {}
  };
  int stoi(const string& num, size_t pos, size_t len) {
    return std::stoi(num.substr(pos, len));
  }
  vector<char> checkOperators(long lastSum, long lastNum, long x, long target) {
    vector<char> ops;
    if (lastSum + x == target) {
      ops.push_back('+');
    }
    if (lastSum - x == target) {
      ops.push_back('-');
    }
    if ((lastSum - lastNum) + lastNum * x == target) {
      ops.push_back('*');
    }
    return ops;
  }
  void addOperators(const string& num, const Expression& e, int target) {
    if (e.end == num.size() - 2 || num[e.end + 1] != '0') {
      int lastAll = stoi(num, e.end + 1, num.size() - e.end);
      for (const char& c : checkOperators(e.sum, e.lastNum, lastAll, target)) {
        answer.push_back(e.output + c +
                         num.substr(e.end + 1, num.size() - e.end));
      }
    }
    for (int i = e.end + 1; i < num.size() - 1; i++) {
      string currentStr = num.substr(e.end + 1, i - e.end);
      int current = stoi(num, e.end + 1, i - e.end);
      addOperators(num,
                   Expression(0, i, e.sum + current, current,
                              e.output + '+' + currentStr),
                   target);
      addOperators(num,
                   Expression(0, i, e.sum - current, -current,
                              e.output + '-' + currentStr),
                   target);
      addOperators(num,
                   Expression(0, i, e.sum - e.lastNum + e.lastNum * current,
                              e.lastNum * current, e.output + '*' + currentStr),
                   target);
      if (current == 0) {
        break;
      }
    }
  }
  vector<string> addOperators(string num, int target) {
    if (num.size() == 0) {
      return answer;
    }
    if (std::stol(num) == target && (num.size() == 1 || num[0] != '0')) {
      answer.push_back(num);
    }
    for (int i = 1; i < num.size(); i++) {
      int current = stoi(num, 0, i);
      Expression e(0, i - 1, current, current, num.substr(0, i));
      addOperators(num, e, target);
      if (current == 0) {
        return answer;
      }
    }
    return answer;
  }
};