class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int a=A[0], b=INT_MIN, max=a+b;
        for(int i=1;i<A.size();i++){
            b=std::max(b, A[i]-i);
            max=std::max(a+b, max);
            if(A[i]+i>a){
                a=A[i]+i;
                b=INT_MIN;
            }
        }
        return max;
    }
};