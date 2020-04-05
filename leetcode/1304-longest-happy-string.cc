class Solution {
public:
    char getMostChar(vector<int>& nums, char except){
      if(except=='a'){
        if(nums[1]==nums[2]&&nums[1]==0){
          return 'e';
        }
        return nums[1]>nums[2]?'b':'c';
      } else if(except=='b'){
        if(nums[0]==nums[2]&&nums[0]==0){
          return 'e';
        }
        return nums[0]>nums[2]?'a':'c';
      } else if(except=='c'){
        if(nums[1]==nums[0]&&nums[1]==0){
          return 'e';
        }
        return nums[0]>nums[1]?'a':'b';
      }
      auto it=max_element(nums.begin(), nums.end());
      if(*it==0){
        return 'e';
      }
      return it-nums.begin()+'a';
    }
    string longestDiverseString(int a, int b, int c) {
      stringstream ss;
      char last1='d';
      char last2='d';
      vector<int> count{a,b,c};
      while(true){
        char except=last1==last2?last1:'d';
        char next=getMostChar(count,except);
        if(next=='e'){
          break;
        }
        ss<<next;
        last2=last1;
        last1=next;
        count[next-'a']--;
      }
      return ss.str();
    }
};