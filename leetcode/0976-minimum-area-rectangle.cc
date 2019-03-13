class Solution {
public:
    bool isPointExist(vector<vector<int>>& points, int x, int y){
        for(vector<int>& p: points){
            if(p[0]==x&&p[1]==y){
                return true;
            }
        }
        return false;
    }

    int minAreaRect(vector<vector<int>>& points) {
        int result=40000*40000;
        for(int i=0;i<points.size()-1;i++){
            vector<int> point1=points[i];
            for(int j=i+1;j<points.size();j++){
                vector<int> point2=points[j];
                if(point1[0]!=point2[0]&&point1[1]!=point2[1]){
                    if(isPointExist(points, point1[0], point2[1])&&isPointExist(points, point2[0], point1[1])){
                        result=min(result, abs(point1[0]-point2[0])*abs(point1[1]-point2[1]));
                    }
                }
            }
        }
        if(result==40000*40000)
            return 0;
        return result;
    }
};