class SummaryRanges {
public:
  std::map<int, int> intervals;  // The first int is the start value, the second value is the length of certain interval.
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    
    void addNum(int val) {
      auto upperBound=intervals.upper_bound(val);
      if(upperBound!=intervals.begin()){
        upperBound--;
        if(upperBound->second>=val){
          // Given value in existing intervals.
          return;
        } else if(val==upperBound->second+1){
          // Given value is the tail of an existing interval.
          upperBound->second++;
          if(upperBound->second==next(upperBound,1)->first-1){
            upperBound->second=next(upperBound,1)->second;
            intervals.erase(next(upperBound,1));
          }
          
          return;
        }
      }
      // Given value is the begin of an existing interval.
      auto itForValPlus1=intervals.find(val+1);
      if(itForValPlus1!=intervals.end()){
        intervals.insert(pair<int, int>(val, itForValPlus1->second));
        intervals.erase(itForValPlus1);
        return;
      }
      intervals.insert(pair<int, int>(val, val));
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> answer;
      for(const auto& interval:intervals){
        answer.push_back(vector({interval.first, interval.second}));
      }
      return answer;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */