class Solution {
public:
    int maxNumberOfFamilies(vector<int>& reservedLabels){
      if(reservedLabels.size()==0){
        return 2;
      }
      bool left(true);
      bool right(true);
      bool center(true);
      sort(reservedLabels.begin(), reservedLabels.end());
      for(int l: reservedLabels){
        if(l==2||l==3){
          left=false;
        } else if(l==4||l==5){
          left=false;
          center=false;
        } else if(l==6||l==7){
          center=false;
          right=false;
        } else if(l==8||l==9){
          right=false;
        }
      }
      if(left&&right){
        return 2;
      }
      if(left||right||center){
        return 1;
      }
      return 0;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
      int answer(0);
      int index(0);
      sort(reservedSeats.begin(), reservedSeats.end());
      int firstSkip=reservedSeats[0][0]-1;
      answer+=firstSkip*2;
      for(int i=(firstSkip+1);i<=n;){
        if(i%1000000==0){
          cout<<i<<endl;
        }
        vector<int> labels;
        while(index<reservedSeats.size()&&reservedSeats[index][0]==i){
          labels.push_back(reservedSeats[index][1]);
          index++;
        }
        answer+=maxNumberOfFamilies(labels);
        if(index<reservedSeats.size()){
          int skip=reservedSeats[index][0]-i-1;
          answer+=skip*2;
          i+=(skip+1);
        } else {
          answer+=(n-i)*2;
          i=n+1;
        }
      }
      return answer;
    }
};