class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int a=0;
        int b=0;
        int answer(0);
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                a=0;
                b=0;
                for(int ii=i;ii<j;ii++){
                    a^=arr[ii];
                }
                for(int k=j;k<arr.size();k++){
                    b^=arr[k];
                    if(a==b){
                        answer++;
                    }
                }
            }
        }
        return answer;
    }
};