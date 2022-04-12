class Solution {
public:
    
     
    int mx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int my[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    int get_live_neighbors(vector<vector<int>> &board, int a, int b)
    {
        int n = 0;
        
        for(int i = 0 ; i < 8 ; i++)
        {
            int x = mx[i] + a, y = my[i] + b;
            
            if(0 <= x and x < board.size() and 0 <= y and y < board[0].size())
                if(board[x][y] == 1 or board[x][y] == 2)
                    n++;
        }
        
        return n;
    }

 void gameOfLife(vector<vector<int>>& board) {
    
     
     /*another approach will creating new copy to store old board state and make change 
     on it to make it next generation by using old board for comparision*/
     
     /*
     old state -> new state  => symbol
              0->0           => 0
              1->1           => 1
              1->0           => 2
              0->1           => 3
              
      so  symbol%2  we get new states i.e. 0 and 1        
     */
     
        
    int m = board.size(), n =  board[0].size();
     
     
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            
            int count = get_live_neighbors(board, i,j) ;
    
              if(board[i][j]==0){
                  
                  if(count==3){
                      board[i][j]=3;     //  0->1
                  }
                  
              }else{
                  
                  if(count<2 || count>3){
                      board[i][j]=2;    // 1->0
                  }
                  
              }     
           
         }
     }
     
     
     for(int i = 0 ; i < m ; i++){
         for(int j = 0 ; j < n ; j++){
               board[i][j] %= 2; 
            }
     }
   
    }
};