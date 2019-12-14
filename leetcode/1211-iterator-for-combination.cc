class CombinationIterator {
public:
    vector<string> combinations;
    int index;
    CombinationIterator(string characters, int combinationLength) {
      if(combinationLength==characters.size()){
        combinations.push_back(characters);
      } else {
        combinations=create(characters, 0, "", combinationLength);
      }
      index=0;
    }
    
    string next() {
        return combinations[index++];
    }
    
    bool hasNext() {
      cout<<"index="<<index<<", size="<<combinations.size()<<endl;
        return index!=combinations.size();
    }
    vector<string> create(const string& characters, int start, const string& prefix, int remain){
      vector<string> answer;
      for(int i=start;i<characters.size();i++){
        if(remain==1){
          answer.push_back(prefix+characters[i]);
        } else {
          vector<string> currentAnswer=create(characters, i+1, prefix+characters[i], remain-1);
          answer.insert(answer.end(), currentAnswer.begin(), currentAnswer.end());
        }
      }
      return answer;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */