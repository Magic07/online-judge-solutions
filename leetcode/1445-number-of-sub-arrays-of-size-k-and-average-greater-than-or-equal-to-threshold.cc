class Solution {
public:
    long long sum(vector<int>& arr, int start, int length){
      long long answer(0);
      for(int i=start;i<start+length;i++){
        answer+=arr[i];
      }
      return answer;
    }
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
      int answer(0);
      long long limit=(long long)threshold*k;
      long long currentSum=sum(arr,0,k);
      if(currentSum>=limit)
        answer++;
      cout<<answer<<endl;
      for(int i=1;i<=arr.size()-k;i++){
        currentSum=currentSum-arr[i-1] +arr[i+k-1];
        if(currentSum>=limit)
          answer++;
      }
      return answer;
    }
};