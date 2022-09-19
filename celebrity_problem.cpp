class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()>=2){
            int i=st.top();
             st.pop();
            int j= st.top();
           
            st.pop();
            if(M[i][j]==1){
                st.push(j);
            }
            else{
                st.push(i);
            }
        }
        int pot = st.top();
        st.pop();
        for(int i=0;i<n;i++){
            if(i!=pot){
                if(M[i][pot]==0||M[pot][i]==1){
                    return -1;
                }
            }
        }
        return pot;
    }
};
