class Solution {
public:
    int findLucky(vector<int>& arr) {
      sort(arr.begin(), arr.end());
      int frequency(0);
      int num(501);
      for(int i=arr.size()-1;i>=0;i--){
        if(arr[i]==num){
          frequency++;
        } else {
          if(frequency==num){
            return num;
          } else {
            frequency=1;
            num=arr[i];
          }
        }
      }
      if(frequency==num){
        return num;
      }
      return -1;
    }
};