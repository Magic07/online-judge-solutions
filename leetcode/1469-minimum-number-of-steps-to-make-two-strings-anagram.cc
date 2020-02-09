class Solution {
public:
  void countChar(const string& str, int result[26]){
    for(const char& c: str){
      result[c-'a']++;
    }
  }
  int diff(int lhs[26], int rhs[26]){
    int answer(0);
    for(int i=0;i<26;i++){
      answer+=abs(lhs[i]-rhs[i]);
    }
    return answer/2;
  }
    int minSteps(string s, string t) {
      int numberOfS[26];
      int numberOfT[26];
      memset(numberOfS, 0, sizeof(numberOfS));
      memset(numberOfT, 0, sizeof(numberOfT));
      countChar(s, numberOfS);
      countChar(t, numberOfT);
      return diff(numberOfS, numberOfT);
    }
};