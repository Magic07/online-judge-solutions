// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int smallOrLarge=rand7();
      while(smallOrLarge==4){
        smallOrLarge=rand7();
      }
      int offset=rand7();
      while(offset>5){
        offset=rand7();
      }
      return offset+(smallOrLarge>4?5:0);
    }
};