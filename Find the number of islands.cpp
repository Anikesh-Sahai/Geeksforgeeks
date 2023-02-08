   //Find the number of islands
   
   
    void Bfs(int i, int j,int n, int m,vector<vector<char>>& grid,vector<vector<bool>>& visited){
        visited[i][j]=true;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            //traversing the neighbour
            for(int k=-1;k<=1;k++){
                for(int l=-1;l<=1;l++){
                    int nrow=row+k;
                    int ncol=col+l;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                        visited[nrow][ncol]=true;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    Bfs(i,j,n,m,grid,visited);
                }
            }
        }
        return count;
    }