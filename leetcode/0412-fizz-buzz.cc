class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> answer(n);
    int fizz = 2;
    int buzz = 4;
    for (int i = 1; i <= n; i++) {
      if (fizz == 0 && buzz == 0) {
        answer[i - 1] = "FizzBuzz";
      } else if (fizz == 0) {
        answer[i - 1] = "Fizz";
      } else if (buzz == 0) {
        answer[i - 1] = "Buzz";
      } else {
        answer[i - 1] = to_string(i);
      }
      if (fizz == 0)
        fizz = 3;
      if (buzz == 0)
        buzz = 5;
      fizz--;
      buzz--;
    }
    return answer;
  }
};