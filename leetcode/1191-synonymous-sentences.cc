#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> generateSentences(vector<vector<string>>& synonyms,
                                   string text) {
    for (vector<string>& s : synonyms) {
      string s0Parent = s[0];
      string s1Parent = s[1];
      if (sIndex.find(s[0]) != sIndex.end()) {
        s0Parent = sIndex[s[0]];
      }
      if (sIndex.find(s[1]) != sIndex.end()) {
        s1Parent = sIndex[s[1]];
      }
      if (sMap.find(s0Parent) != sMap.end()) {
        if (sMap.find(s1Parent) == sMap.end()) {
          sMap[s0Parent].push_back(s[1]);
          sIndex[s[1]] = s0Parent;
        } else {
          // Merge.
          for (const string& sOfs1 : sMap[s1Parent]) {
            sIndex[sOfs1] = s0Parent;
          }
          sMap[s0Parent].insert(sMap[s0Parent].end(), sMap[s1Parent].begin(),
                                sMap[s1Parent].end());
          sMap.erase(s1Parent);
        }
      } else if (sMap.find(s1Parent) != sMap.end()) {
        sMap[s1Parent].push_back(s[0]);
        sIndex[s[0]] = s1Parent;
      } else {
        sMap[s[0]].push_back(s[0]);
        sMap[s[0]].push_back(s[1]);
        sIndex[s[1]] = s[0];
      }
    }
    vector<string> words;
    std::istringstream iss(text);
    while (iss) {
      string s;
      iss >> s;
      words.push_back(s);
    }
    words.pop_back();
    // cout << "words size: " << words.size() << endl;
    dfs(words, 0, "");
    std::sort(answer.begin(), answer.end());
    return answer;
  }
  void dfs(const vector<string>& words, int index, string current) {
    if (index == words.size()) {
      answer.push_back(current);
      return;
    }
    if (index != 0) {
      current = current + ' ';
    }
    string currentWord = words[index];
    if (sIndex.find(currentWord) != sIndex.end()) {
      currentWord = sIndex[currentWord];
    }
    if (sMap.find(currentWord) != sMap.end()) {
      // cout << "Index " << index << " has synonyms." << endl;
      vector<string> alternatives(sMap[currentWord]);
      // cout << "Althernative size: " << alternatives.size() << endl;
      for (const string& a : alternatives) {
        dfs(words, index + 1, current + a);
      }
    } else {
      // cout << "Index " << index << " doesn't have synonyms." << endl;
      dfs(words, index + 1, current + currentWord);
    }
  }

 private:
  vector<string> answer;
  unordered_map<string, vector<string>> sMap;
  unordered_map<string, string> sIndex;
};