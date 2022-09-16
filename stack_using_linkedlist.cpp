void MyStack ::push(int x) 
{
    // Your Code
    StackNode *newNode = new StackNode(x);
    newNode->next=top;
    top=newNode;
    
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
    if(top==NULL)return -1;
    int topData = top->data;
    StackNode *temp=top;
    top=top->next;
    delete temp;
    return topData;
}
