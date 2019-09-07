class Solution {
 public:
  string countAndSay(int n) {
    if (n == 0) {
      return string("");
    }
    if(n==1){
      return string("1");
    }
    string str("1");
    for (int i = 1; i < n; i++) {
      int last = str[0]-48;  // 48 is the difference between number 1 and char 1.
      int count = 1;
      stringstream ss;
      for (int j = 1; j < str.size(); j++) {
        if (str[j]-48 == last) {
          count++;
        } else {
          ss << count << last;
          last = str[j]-48;
          count = 1;
        }
      }
      ss << count << last;
      str = ss.str();
    }
    return str;
  }
};
