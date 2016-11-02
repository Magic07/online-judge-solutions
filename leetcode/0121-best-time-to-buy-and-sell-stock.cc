class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() == 0)
      return 0;
    int answer(0), min_value(prices[0]), max_value(prices[0]);
    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] > max_value) {
        max_value = prices[i];
        answer = max(answer, max_value - min_value);
      } else if (prices[i] < min_value) {
        min_value = prices[i];
        max_value = prices[i];
      }
    }
    return answer;
  }
};