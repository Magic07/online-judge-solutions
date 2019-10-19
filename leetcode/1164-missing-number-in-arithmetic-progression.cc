class Solution {
public:
    int missingNumber(vector<int>& arr) {
      int diff=abs(arr[arr.size()-1]-arr[0])/arr.size();
      if(arr[0]>arr[1]){
        diff=0-diff;
      }
      for(int i=0;i<arr.size();i++){
        if(arr[i]!=arr[0]+diff*i){
          return arr[0]+diff*i;
        }
      }
      return 0;
    }
};