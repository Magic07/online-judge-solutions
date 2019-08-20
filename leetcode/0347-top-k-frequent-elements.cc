#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> elements;
    for (int num : nums) {
      elements[num]++;
    }
    vector<int> answer;
    auto cmp = [](pair<int, int> lhs, pair<int, int> rhs) {
      return lhs.second < rhs.second;
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> data(cmp);
    for(auto& e: elements){
      cout<<"Insert ("<<e.first<<", "<<e.second<<")."<<endl;
      data.push(e);
    }
    for(int i=0;i<k;i++){
      answer.push_back(data.top().first);
      data.pop();
    }
    return answer;
  }
};