class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
      int lastX=coordinates[0][0];
      bool sameCol=true;
      for(const vector<int>& c: coordinates){
        if(c[0]!=lastX){
          sameCol=false;
          break;
        }
      }
      if(sameCol){
        cout<<"Return true"<<endl;
        return true;
      }
      double gradient=(double)(coordinates[1][1]-coordinates[0][1])/(double)(coordinates[1][0]-coordinates[0][0]);
      cout<<"gradient="<<coordinates[1][1]-coordinates[0][1]<<endl;
      for(int i=2;i<coordinates.size();i++){
        if((coordinates[i][0]==coordinates[i-1][0])){
          return false;
        }
        if((coordinates[i][1]-coordinates[i-1][1])/(coordinates[i][0]-coordinates[i-1][0])!=gradient){
          return false;
        }
      }
      return true;
    }
};