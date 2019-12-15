class Solution {
 public:
  int getSequentialNumber(int length, int start) {
    cout<<"length "<<length<<", start: "<<start<<endl;
    int answer(start);
    length--;
    int currentDigit(start + 1);
    while (length != 0) {
      if (currentDigit > 9) {
        return getSequentialNumber(length + 1, 1);
      }
      answer *= 10;
      answer += currentDigit;
      currentDigit++;
      length--;
    }
    cout << answer << endl;
    return answer;
  }
  int sizeOfNumber(int x){
    stack<int> s;
    while (x) {
      s.push(x % 10);
      x /= 10;
    }
    return s.size();
  }
  int getNextSequentialNumber(int x) {
    int a=x;
    stack<int> s;
    while (x) {
      s.push(x % 10);
      x /= 10;
    }
    int length = s.size();
    int maybeAnswer = getSequentialNumber(length, s.top());
    if (maybeAnswer < a) {
      int start = s.top();
      if (start >= 10-length) {
        start = 1;
        length++;
        if(length==10){
          return INT_MAX;
        }
      } else {
        start++;
      }
      return getSequentialNumber(length, start);
    } else {
      return maybeAnswer;
    }
  }
  vector<int> sequentialDigits(int low, int high) {
    vector<int> answer;
    while (low < high) {
      int number = getNextSequentialNumber(low);
      //cout<<number<<endl;
      if (number < min(high, 123456789)) {
        cout<<"push "<<number<<endl;
        answer.push_back(number);
        low = number + 1;
      } else {
        if(number==123456789&&number<high){
          answer.push_back(number);
        }
        return answer;
      }
    }
    return answer;
  }
};