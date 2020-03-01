class Solution {
public:
  struct ScoreBoard{
    char team;
    int* votes;
    int totalVotes;
    ScoreBoard(char t, int* v, int total):team(t),votes(v),totalVotes(total){};
  };
  string rankTeams(vector<string>& votes) {
    int v[26][1000];
    memset(v, 0, sizeof(v));
    for(int i=0;i<votes.size();i++){
      for(int j=0;j<votes[i].size();j++){
        char team=votes[i][j];
        v[team-'A'][j]++;
      }
    }
    vector<ScoreBoard> s;
    for(int i=0;i<26;i++){
      int sum(0);
      for(int j=0;j<votes[0].size();j++){
        sum+=v[i][j];
      }
      s.push_back(ScoreBoard('A'+i, v[i], sum));
    }
    sort(s.begin(), s.end(),[&votes](const ScoreBoard& lhs, const ScoreBoard& rhs){
      if(lhs.totalVotes<rhs.totalVotes){
        return true;
      } else if(lhs.totalVotes==rhs.totalVotes){
        for(int i=0;i<votes[0].size();i++){
          if(lhs.votes[i]<rhs.votes[i]){
            return true;
          } else if(lhs.votes[i]>rhs.votes[i]){
            return false;
          }
        }
        return lhs.team>rhs.team;
      } else {
        return false;
      }
    });
    stringstream ss;
    for(int i=s.size()-1;i>=0;i--){
      if(s[i].totalVotes==0){
        break;
      }
      ss<<s[i].team;
    }
    return ss.str();
  }
};