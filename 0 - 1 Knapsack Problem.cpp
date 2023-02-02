    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int solveDP(int i, int w, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        if(w==0 || i==n)
             return 0;
        
        if(dp[i][w] != -1)
            return dp[i][w];
        
        int notIncluded = solveDP(i+1, w, wt, val, n, dp);
        
        int included = INT_MIN;
        
        if(wt[i]<=w)
            included = val[i] + solveDP(i+1, w-wt[i], wt, val, n, dp);
            
        
        return dp[i][w] = max(included, notIncluded);
            
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
       //n,m,l
    //   vector<vector<vector<int>>> 3d(n, vector<vector<int>>(m, vector<int>(l, -1)))
    
        return solveDP(0, W, wt, val, n, dp);
    }
