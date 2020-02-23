class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
      if(digits.size()==1){
        if(digits[0]%3==0){
          stringstream ss;
          ss<<digits[0];
          return ss.str();
        } else {
          return "";
        }
      }
      vector<bool> removed(digits.size(), false);
      sort(digits.begin(), digits.end());
      int sum=accumulate(digits.begin(), digits.end(), 0);
      int r=sum%3;
      if(r!=0){
        for(int i=0;i<digits.size();i++){
          if(digits[i]%3==r){
            removed[i]=true;
            sum-=digits[i];
            break;
          }
        }
        if(sum%3!=0){
          for(int i=0;i<digits.size()-1;i++){
            for(int j=i+1;j<digits.size();j++){
              if((digits[i]+digits[j])%3==r){
                removed[i]=true;
                removed[j]=true;
                sum-=digits[i];
                sum-=digits[j];
                break;
              }
            }
            if(sum%3==0){
                break;
            }
          }
        }
        if(sum%3!=0){
          return "";
        }
      }
      if(digits[digits.size()-1]==0&&removed[digits.size()-1]==false){
        return "0";
      }
      if(digits.size()>=2&&digits[digits.size()-2]==0&&removed[digits.size()-2]==false&&removed[digits.size()-1]){
        return "0";
      }
      if(digits.size()>=3&&digits[digits.size()-3]==0&&removed[digits.size()-3]==false&&removed[digits.size()-1]&&removed[digits.size()-2]){
        return "0";
      }
      stringstream ss;
      for(int i=digits.size()-1;i>=0;i--){
        if(!removed[i]){
          ss<<digits[i];
        }
      }
      return ss.str();
    }
};