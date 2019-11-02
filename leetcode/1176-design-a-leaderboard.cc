class Leaderboard {
public:
    std::unordered_map<int, int> scoreMap;
    Leaderboard() {
    }
    
    void addScore(int playerId, int score) {
        scoreMap[playerId]+=score;
    }
    
    int top(int K) {
      std::vector<std::pair<int, int>> scoreList;
      for (auto it = scoreMap.begin(); it != scoreMap.end(); it++){
        scoreList.push_back(*it);
      }
      sort(scoreList.begin(), scoreList.end(), [](std::pair<int, int>& lhs, std::pair<int, int>& rhs){
        return lhs.second > rhs.second;
      });
      int answer(0);
      for(int i=0;i<K;i++){
        answer+=scoreList[i].second;
      }
      return answer;
    }
    
    void reset(int playerId) {
        scoreMap[playerId]=0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */