#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class myStack{
struct Node{
    struct Node *next;
    struct Node *prev;
    int data;
    Node (int x){
        data=x;
        next=prev=NULL;
    }
};
Node *dummy = new Node(-1);
Node *head = dummy;
Node *mid = dummy;
int count = 0;
public:
void push(int data){
    Node *cur = new Node (data);
    cur->prev=NULL;
    cur->next=head;
    count++;
    head->prev = cur;
    head=cur;
    if(count==1){
        mid=cur;
    }
    else if(count%2==0){
        mid=mid->prev;
    }
}
int pop(){
    if(count==0){
        cout<<"Stack is empty"<<" ";
        return -1;
    }
    Node *temp = head;
    int x = head->data;
    head = head->next;
    if(head!=NULL)
    head->prev=NULL;
    count--;
    if(count&1)mid=mid->next;
    free(temp);
    return x;
}
int middle(){
    if(count==0){
        cout<<"Stack is empty";
        return -1;
    }
    return mid->data;
}
void printData(){
    Node *cur=head;
    if(count==0){
        cout<<"Stack is Empty"<<endl;
        return;
    }
    for(int i=0;i<count;i++){
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    cout<<endl;
}
};

int main()
{
    myStack st;
st.push(1);
st.push(2);
st.push(3);
st.push(4);
st.push(5);
st.push(6);
st.pop();
st.printData();
cout<<"Middle Element is "<<st.middle()<<endl;
    return 0;
}
