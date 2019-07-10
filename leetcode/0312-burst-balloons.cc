class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int r[nums.size()][nums.size()];
        memset(r,0,sizeof(r));
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i;j<nums.size();j++){
                int value=0;
                for(int k=i;k<=j;k++){
                    int left=(i-1>=0)?nums[i-1]:1;
                    int right=(j+1<nums.size())?nums[j+1]:1;
                    int numsSize=nums.size();
                    int maxLeft=k-1>=0?r[i][k-1]:0;
                    int maxRight=k+1<numsSize?r[k+1][j]:0;
                    value=max(value, maxLeft+maxRight+left*nums[k]*right);
                }
                r[i][j]=value;
            }
        }
        return r[0][nums.size()-1];
    }
};