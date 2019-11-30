class Solution {
 public:
  string toHexadecimal(string num) {
    char hexChar[16] = {'O', 'I', '2', '3', '4', '5', '6', '7',
                        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    long long decimal = stoll(num);
    stack<char> hexDigitals;
    while (decimal != 0) {
      hexDigitals.push(hexChar[decimal % 16]);
      decimal /= 16;
    }
    stringstream ss;
    while (!hexDigitals.empty()) {
      ss << hexDigitals.top();
      hexDigitals.pop();
    }
    return ss.str();
  }
  string toHexspeak(string num) {
    if (num == "0") {
      return "O";
    }
    string hex = toHexadecimal(num);
    for (const char c : hex) {
      switch (c) {
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          return "ERROR";
      }
    }
    return hex;
  }
};