class Solution {
public:
    struct Node{
      int left;
      int right;
      Node(int left, int right):left(left), right(right){ }
    };
    bool visitNodes(vector<Node*>& nodes, int index, vector<bool>& visited){
      if(index==-1){
        return true;
      }
      if(visited[index]){
        return false;
      }
      visited[index]=true;
      return (visitNodes(nodes, nodes[index]->left, visited)&&visitNodes(nodes, nodes[index]->right, visited));
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
      vector<Node*> nodes(leftChild.size());
      vector<bool> visited(leftChild.size(), false);
      for(int i=0;i<leftChild.size();i++){
        nodes[i]=new Node(leftChild[i], rightChild[i]);
      }
      if(!visitNodes(nodes, 0, visited)){
        return false;
      }
      for(bool v: visited){
        if(!v){
          return false;
        }
      }
      return true;
    }
};