class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
      if(arr.size()==1){
        return arr[0];
      }
      int last=arr[0];
      int ap=0;
      for(int i=1;i<arr.size();i++){
        if(arr[i]==last){
          ap++;
          if(ap>arr.size()*0.25){
            return last;
          }
        } else {
          ap=0;
          last=arr[i];
        }
      }
      return last;
    }
};