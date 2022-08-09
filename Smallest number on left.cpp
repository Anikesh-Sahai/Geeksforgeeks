class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        vector<int> v;
        stack<int> s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                v.push_back(-1);
                s.push(a[i]);
            }
            else{
                if(s.top()<a[i]){
                    v.push_back(s.top());
                    s.push(a[i]);
                }
                else{
                    while(s.size()>0 && s.top()>=a[i]){
                        s.pop();
                    }
                    if(s.empty()){
                        v.push_back(-1);
                        s.push(a[i]);
                    }
                    else{
                        v.push_back(s.top());
                        s.push(a[i]);
                    }
                }
            }
        }
        return v;
    }
};