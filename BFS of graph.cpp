    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V);
        vector<int> Bfs;
        queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            Bfs.push_back(temp);
            for(int i: adj[temp]){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        return Bfs;
    }