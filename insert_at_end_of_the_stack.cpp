void insert_at_bottom(int x){
    if(st.size()==0){
        st.push(x);
    }
    else{
        int a = st.top();
        st.pop();
        insert_at_bottom(x);
        st.push(a);
    }
}
