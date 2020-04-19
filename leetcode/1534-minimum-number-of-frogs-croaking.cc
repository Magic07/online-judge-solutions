class Solution {
public:
    bool isValid(vector<int>& numbers){
      for(int i=1;i<5;i++){
        if(numbers[i]>numbers[i-1]){
          return false;
        }
      }
      return true;
    }
    int minNumberOfFrogs(string croakOfFrogs) {
      string croak("croak");
      vector<int> numbers(5);
      int answer(0);
      for(char c: croakOfFrogs){
        auto index=croak.find(c);
        if(index!=std::string::npos){
          numbers[index]++;
        }
        if(!isValid(numbers)){
          return -1;
        }
        int lowest=*min_element(numbers.begin(), numbers.end());
        if(lowest>0){
          for(int i=0;i<5;i++){
            numbers[i]-=lowest;
          }
        }
        int highest=*max_element(numbers.begin(), numbers.end());
        answer=max(answer, highest);
      }
      int highest=*max_element(numbers.begin(), numbers.end());
      if(highest!=0){
        return -1;
      }
      return answer;
    }
};