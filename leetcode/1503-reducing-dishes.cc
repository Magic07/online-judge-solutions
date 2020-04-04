class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
      sort(satisfaction.begin(),satisfaction.end(),std::greater<int>());
      int time(1);
      int answer(0);
      int satisfactionSum(0);
      for(int s: satisfaction){
        if(s+answer+satisfactionSum>=answer){
          answer=s+answer+satisfactionSum;
          satisfactionSum+=s;
        }
      }
      return answer;
    }
};