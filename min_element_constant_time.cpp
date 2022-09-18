class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
              if(s.size() == 0)
              return -1;
          return minEle;
           //Write your code here
       }
       
       /*returns poped element from stack*/
       int pop(){
               if(s.empty())
           {return -1;}
          int t=s.top();
          s.pop();
          int res;
          if(t<=minEle)
          {
              res=minEle;
              minEle=2*minEle-t;
              return res;
          }
          else
          {
              return t;
          }
           //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int x){
                   if(s.empty())
          {
              minEle=x;
              s.push(x);
          }
          else if(x<=minEle)
          {
              s.push(2*x-minEle);
              minEle=x;
          }
          else
          {
              s.push(x);
          }
           
       }
};
