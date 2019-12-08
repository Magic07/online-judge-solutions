class Solution {
public:
    bool isOkay(vector<int>& nums, int divisor, int threshold){
      int sum(0);
      for(int n:nums){
        sum+=ceil((float)n/(float)divisor);
      }
      if(sum<=threshold){
        return true;
      } else{
        return false;
      }
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
      int max=*max_element(nums.begin(), nums.end());
      int min=1;
      int lastMin(0);
      while(min<max-1){
        int mid=std::max((max+min)/2,lastMin+1);
        if(!isOkay(nums, mid, threshold)){
          min=mid;
        } else {
          max=mid;
        }
        lastMin=min;
      }
      if(min=max-1){
        if(isOkay(nums, min, threshold)){
          return min;
        }
      }
      return max;
    }
};