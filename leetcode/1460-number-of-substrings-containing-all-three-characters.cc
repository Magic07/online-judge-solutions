class Solution {
public:
    int numberOfSubstrings(string s) {
      int nextA[50000];
      int nextB[50000];
      int nextC[50000];
      memset(nextA, 0, sizeof(nextA));
      memset(nextB, 0, sizeof(nextB));
      memset(nextC, 0, sizeof(nextC));
      int currentA(INT_MAX);
      int currentB(INT_MAX);
      int currentC(INT_MAX);
      for(int i=s.size()-1;i>=0;i--){
        nextA[i]=currentA;
        nextB[i]=currentB;
        nextC[i]=currentC;
        if(s[i]=='a') currentA=i;
        if(s[i]=='b') currentB=i;
        if(s[i]=='c') currentC=i;
      }
      int answer(0);
      for(int i=0;i<=s.size()-3;i++){
        if(s[i]=='a'){
          if(max(nextB[i],nextC[i])<50001)
            answer+=s.size()-max(nextB[i],nextC[i]);
        }
        if(s[i]=='b'){
          if(max(nextA[i],nextC[i])<50001)
            answer+=s.size()-max(nextA[i],nextC[i]);
        }
        if(s[i]=='c'){
          if(max(nextA[i],nextB[i])<50001)
            answer+=s.size()-max(nextA[i],nextB[i]);
        }
      }
      return answer;
    }
};