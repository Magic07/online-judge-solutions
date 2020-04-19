class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
      vector<string> items;
      map<int, unordered_map<string, int>> orderMap;
      int maxTableNumber(0);
      for(auto& o: orders){
        string table=o[1];
        int tableNumber=stoi(table);
        string item=o[2];
        if(find(items.begin(), items.end(), item)==items.end()){
          items.push_back(item);
        }
        orderMap[tableNumber][item]++;
      }
      vector<vector<string>> answer;
      vector<string> title;
      title.push_back("Table");
      std::sort(items.begin(), items.end());
      for(string& i: items){
        title.push_back(i);
      }
      answer.push_back(title);
      for(auto it=orderMap.begin();it!=orderMap.end();++it){
        vector<string> t;
        t.push_back(std::to_string(it->first));
        for(string& i: items){
          if(it->second.find(i)==it->second.end()){
            t.push_back("0");
          } else {
            t.push_back(std::to_string(it->second[i]));
          }
        }
        answer.push_back(t);
      }
      return answer;
    }
};