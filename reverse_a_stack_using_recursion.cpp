#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
stack<int> st;
void insert_at_bottom(char x){
    if(st.size()==0) st.push(x);
    else{
        char a = st.top();
        st.pop();
        insert_at_bottom(x);
        st.push(a);
    }
}
void reverse(){
    if(st.size()>0){
        char x = st.top();
        st.pop();
        reverse();
        insert_at_bottom(x);
    }
    return;
}



int main()
{
   for(int i=0;i<=4;i++){
       st.push(i);
   }
//   while(!st.empty()){
//       cout<<st.top()<<endl;
//       st.pop();
//   }
   
   reverse();
   while(!st.empty()){
       cout<<st.top()<<endl;
       st.pop();
   }
    return 0;
}
