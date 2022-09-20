void QueueStack :: push(int x)
{
        // Your Code
        q2.push(x);
        while(q1.size()!=0){
            q2.push(q1.front());
            q1.pop();
        }
        while(q2.size()!=0){
            q1.push(q2.front());
            q2.pop();
        }
       
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code  
        
      int x = q1.front();
      q1.pop();
      return x;
}
