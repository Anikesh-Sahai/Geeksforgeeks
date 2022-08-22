//Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.
// using MAH function as an optimal solution 
class Solution{
  public:
    
    int MAH(vector<int> heights){
        stack<int> s;
        int maxA=0;
        int n=heights.size();
        for(int i=0; i<=n;i++){
            while(!s.empty() && (i==n || heights[s.top()]>=heights[i])){
                int height= heights[s.top()];
                s.pop();
                int width;
                if(s.empty()) width=i;
                else width=i-s.top()-1;
                maxA=max(maxA,height*width);
            }
            s.push(i);
        }
        return maxA;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        int maximumArea=0;
        vector<int> height;
        // using m for column that is i and n for row that is j
        for(int i=0;i<m;i++){
            height.push_back(M[0][i]);
        }
        maximumArea=max(maximumArea,MAH(height));
        for(int j=1;j<n;j++){
            for(int i=0;i<m;i++){
                if(M[j][i]==0) height[i]=0;
                else height[i]=height[i]+M[j][i];
            }
            maximumArea=max(maximumArea,MAH(height));
        }
        return maximumArea;
    }
};