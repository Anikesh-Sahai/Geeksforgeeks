// You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

/*The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
            if(s.empty()) return -1;
            else return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(s.empty()) return -1;
           else{
                if(s.top()>=minEle){
                    int t=s.top();
                    s.pop();
                    return t;
                }
                else{
                    int t= minEle;
                    minEle=(2*minEle)-s.top();
                    s.pop();
                    return t;
                }
           }    
       }
       
        int top() {
            if(s.empty()) return -1;
            else{
                if(s.top()>=minEle) return s.top();
                else return minEle;
            }
        
        }
       
       /*push element x into the stack*/
       void push(int x){
           if(s.empty()){
            s.push(x);
            minEle=x;
            }
            else{
                if(x>=minEle) s.push(x);
                else{
                    s.push((2*x)-minEle);
                    minEle=x;
                }
            }
        }