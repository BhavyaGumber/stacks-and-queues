#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
 
class Queue
{
    // Initialize front and rear
    int rear, front;
 
    // Circular Queue
    int size;
    int *arr;
public:
    Queue(int s)
    {
       front = rear = -1;
       size = s;
       arr = new int[s];
    }
    void enqueue(int data){
        if((rear+1)%n==front){
            return;
        }
        if(front==-1)front=0;
        rear=(rear+1)%n;
        arr[rear] = data;
    }
    int dequeue(){
        if(front==-1){
            return -1;
        }
        int result = arr[front];
        if(front==rear)front=rear=-1;
        else{
            front=(front+1)%n;
        }
        return result;
    }
};

