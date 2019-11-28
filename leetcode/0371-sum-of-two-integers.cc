class Solution {
 public:
  int getSum(int a, int b) {
    int answer(0);
    int carry(0);
    int mask(1);
    for (; mask > 0; mask = mask << 1, carry = carry << 1) {
      int currentDigital = ((a & mask) ^ (b & mask) ^ (carry & mask));
      answer = answer | currentDigital;
      carry = (a & b & mask) | (b & carry & mask) | (a & carry & mask);
    }
    int currentDigital = ((a & mask) ^ (b & mask) ^ (carry & mask));
    answer = answer | currentDigital;
    return answer;
  }
};