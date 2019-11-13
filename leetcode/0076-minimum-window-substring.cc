class Solution {
public:
    string minWindow(string s, string t) {
      int count[128]={0};
      int remain(t.size());
      for(char c:t){
        count[c]++;
      }
      int begin=0, end=0, answerBegin=0, length=INT_MAX;
      while(end<s.size()){
        if(count[s[end]]-->0){
          remain--;
        }
        end++;
        while(remain==0){
          if(end-begin<length){
            length=end-begin;
            answerBegin=begin;
          }
          if(count[s[begin++]]++==0){
            remain++;
          }
        }
      }
      if(length==INT_MAX){
        return "";
      } else {
        return s.substr(answerBegin, length);
      }
    }
};