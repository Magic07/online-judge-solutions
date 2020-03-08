class Solution {
public:
    int findTheLongestSubstring(string s) {
      string vowels("aeiou");
      unordered_map<int, int> firstSeen;
      firstSeen[0]=-1;
      int state(0);
      int answer(0);
      for(int i=0;i<s.size();i++){
        size_t index=vowels.find(s[i]);
        if(index!=std::string::npos){
          state^=(1<<index);
        }
        if(firstSeen.find(state)!=firstSeen.end()){
          answer=max(answer, i-firstSeen[state]);
        } else {
          firstSeen[state]=i;
        }
      }
      return answer;
    }
};