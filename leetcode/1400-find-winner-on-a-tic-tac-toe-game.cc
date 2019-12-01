class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
      char game[3][3];
      memset(game, 0,sizeof(game));
      for(int i=0;i<moves.size();i++){
        if(i%2==0){
          game[moves[i][0]][moves[i][1]]='X';
        } else {
          game[moves[i][0]][moves[i][1]]='O';
        }
      }
      for(int i=0;i<3;i++){
        if(game[i][0]==game[i][1]&&game[i][1]==game[i][2]){
          if(game[i][0]=='X'){
            return "A";
          } else if (game[i][0]=='O'){
            return "B";
          }
        }
        if(game[0][i]==game[1][i]&&game[1][i]==game[2][i]){
          if(game[0][i]=='X'){
            return "A";
          } else if(game[0][i]=='O') {
            return "B";
          }
        }
      }
      if((game[1][1]==game[0][0]&&game[1][1]==game[2][2])||(game[1][1]==game[0][2]&&game[1][1]==game[2][0])){
        if(game[1][1]=='X'){
          return "A";
        } else if(game[1][1]=='O'){
          return "B";
        }
      }
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          if(game[i][j]!='X'&&game[i][j]!='O'){
            return "Pending";
          }
        }
      }
      return "Draw";
    }
};