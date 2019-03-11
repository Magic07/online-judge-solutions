class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> r;
        if(k==0){
            return r;
        }
        for(const int& e:arr){
            if(r.size()<k){
                r.push_back(e);
            } else if(abs(x-e)-abs(x-r[0])<0){
                r.erase(r.begin());
                r.push_back(e);
            } else if(e>x){
                return r;
            }
        }
        return r;
    }
};