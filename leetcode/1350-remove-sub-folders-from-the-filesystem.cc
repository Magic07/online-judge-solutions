#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> removeSubfolders(vector<string>& folder) {
    int MAX_LENGTH=40000;
    bool deleted[MAX_LENGTH];
    memset(deleted, 0, sizeof(deleted));
    sort(folder.begin(), folder.end());
    string last=folder[0]+'/';
    for (int i = 1; i <folder.size(); i++) {
      if(folder[i].find(last)==0){
        deleted[i]=true;
      } else {
        last=folder[i]+'/';
      }
    }
    vector<string> answer;
    for(int i=0;i<folder.size();i++){
      if(!deleted[i]){
        answer.push_back(folder[i]);
      }
    }
    return answer;
  }
};