class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int bCount=0, aCount=0, lCount=0, oCount=0, nCount=0;
      for(auto& c:text){
        if(c=='b'){
          bCount++;
          continue;
        }
        if(c=='a'){
          aCount++;
          continue;
        }
        if(c=='l'){
          lCount++;
          continue;
        }
        if(c=='o'){
          oCount++;
          continue;
        }
        if(c=='n'){
          nCount++;
          continue;
        }
      }
      int answer=INT_MAX;
      answer=min(answer, bCount);
      answer=min(answer, aCount);
      answer=min(answer, lCount/2);
      answer=min(answer, oCount/2);
      answer=min(answer, nCount);
      return answer;
    }
};