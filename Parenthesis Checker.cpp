class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> stk;
        int n=x.length();
        for(int i=0;i<n;i++){
            if(x[i]=='(' || x[i]=='[' || x[i]=='{'){
                stk.push(x[i]);
            }
            if(x[i]==')' || x[i]==']' || x[i]=='}'){
                if(stk.empty()){return false;}
                else{
                    if(stk.top()=='(' && x[i]==')'  || stk.top()=='[' && x[i]==']'  || stk.top()=='{' && x[i]=='}'){
                        stk.pop();
                    }
                    else{return false;}
                }
            }
        }
        if(stk.empty()){
            return true;
        }
        return false;    }

};