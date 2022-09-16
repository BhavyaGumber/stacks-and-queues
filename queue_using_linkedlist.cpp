void MyQueue:: push(int x)
{
        // Your Code
        if(front==NULL){
             QueueNode *end = new QueueNode(x);
             front=end;
             rear=end;
        }
        else{QueueNode *end = new QueueNode(x);
        rear->next=end;
        rear=rear->next;
        }
        
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code  
        if(front==NULL)return -1;
        QueueNode *temp=front;
        front=front->next;
        int x= temp->data;
        delete temp;
        return x;
}
