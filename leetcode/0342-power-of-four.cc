class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        if(num==1)
            return true;
        int exp=log(num)/log(4);
        int r=pow(4, exp);
        return r==num;
    }
};