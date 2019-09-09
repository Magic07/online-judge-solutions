class Solution {
public:
    int firstUniqChar(string s) {
      int position[26];
      fill_n(position, 26, -1);  // -1 means no such character.
      for(int i=0;i<s.size();i++){
        if(position[s[i]-'a']==-1){
          position[s[i]-'a']=i;
        } else {
          position[s[i]-'a']=INT_MAX;  // Not unique;
        }
      }
      bool exist=false;
      int answer=INT_MAX;
      for(int i=0;i<26;i++){
        if(position[i]!=-1&&position[i]!=INT_MAX){
          exist=true;
          answer=min(answer, position[i]);
        }
      }
      if(!exist){
        return -1;
      }
      return answer;
    }
};