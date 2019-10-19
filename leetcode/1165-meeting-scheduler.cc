bool compareSlots(const vector<int>& lhs, const vector<int>& rhs) {
  return lhs[0] < rhs[0];
}

class Solution {
 public:
  vector<int> minAvailableDuration(vector<vector<int>>& slots1,
                                   vector<vector<int>>& slots2,
                                   int duration) {
    sort(slots1.begin(), slots1.end(), compareSlots);
    sort(slots2.begin(), slots2.end(), compareSlots);
    auto it1 = slots1.begin(), it2 = slots2.begin();
    while (it1 != slots1.end() && it2 != slots2.end()) {
      vector<int> v1 = *it1;
      vector<int> v2 = *it2;
      if (v1[0] > v2[1]) {
        cout<<"it2++"<<endl;
        it2++;
        continue;
      } else if (v2[0] > v1[1]) {
        cout<<"it1++"<<endl;
        it1++;
        continue;
      }
      int start = max(v1[0], v2[0]);
      cout<<"start="<<start<<", v1=["<<v1[0]<<", "<<v1[1]<<"], v2=["<<v2[0]<<", "<<v2[1]<<"]"<<endl;
      if (start + duration <= v1[1] && start + duration <= v2[1]) {
        vector<int> answer = {start, start + duration};
        cout<<"find answer."<<endl;
        return answer;
      } else if (start + duration > v1[1]) {
        cout<<"2 it1++"<<endl;
        it1++;
      } else {
        cout<<"2 it2++"<<endl;
        it2++;
      }
    }
    return vector<int>();
  }
};