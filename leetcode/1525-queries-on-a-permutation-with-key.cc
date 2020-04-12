class Solution {
public:
    int position(vector<int>& p, int target){
      for(int i=0;i<p.size();i++){
        if(p[i]==target){
          return i;
        }
      }
      assert(false);
      return -1;
    }
    vector<int> processQueries(vector<int>& queries, int m) {
      vector<int> p(m);
      vector<int> answer;
      for(int i=0;i<m;i++){
        p[i]=i+1;
      }
      for(int i=0;i<queries.size();i++){
        int index=position(p, queries[i]);
        answer.push_back(index);
        for(int j=index;j>0;j--){
          p[j]=p[j-1];
        }
        p[0]=queries[i];
      }
      return answer;
    }
};