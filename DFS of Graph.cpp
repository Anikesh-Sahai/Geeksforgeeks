    // Function to return a list containing the DFS traversal of the graph.
 
 
 
 void DFS(int src,vector<int>& Dfs,vector<bool>& visited, vector<int> adj[]){
      visited[src]=true;
      Dfs.push_back(src);
      for(int i: adj[src]){
          if(!visited[i]){
              DFS(i,Dfs,visited,adj);
          }
      }
  }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>Dfs;
        vector<bool> visited(V);
        DFS(0,Dfs,visited,adj);
        return Dfs;
    }