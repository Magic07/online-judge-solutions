class Solution {
public:
    int minimumSwap(string s1, string s2) {
      if(s1.size()==0){
        return 0;
      }
      int xInS1(0);
      int xInS2(0);
      for(int i=0;i<s1.size();i++){
        if(s1[i]==s2[i]){
          continue;
        }
        if(s1[i]=='x'){
          xInS1++;
        } else {
          xInS2++;
        }
      }
      if((xInS1+xInS2)%2){
        return -1;
      }
      return xInS1/2+xInS2/2+xInS1%2*2;
    }
};