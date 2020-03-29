class UndergroundSystem {
public:
    // {start: {stop: [averageTime, travels]}}.
    unordered_map<string, unordered_map<string,vector<double>>> averageTime;
    // {ID, {start, checkInTime}}.
    unordered_map<int, pair<string, int>> travels;
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
      travels[id]=pair<string,int>{stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
      string start=travels[id].first;
      auto& averageRecord=averageTime[start][stationName];
      if(averageRecord.size()==0){
        averageRecord=vector<double>{(double)t-travels[id].second,1};
      } else {
        double sum=averageRecord[0]*averageRecord[1];
        sum+=(t-travels[id].second);
        averageRecord[1]++;
        averageRecord[0]=sum/averageRecord[1];
      }
      travels.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
      if(averageTime[startStation].find(endStation)!=averageTime[startStation].end()){
        return averageTime[startStation][endStation][0];
      } else {
        return 0;
      }
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */