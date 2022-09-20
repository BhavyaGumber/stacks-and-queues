class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int> st;
        int j=0;
        for(int i=0;i<N;i++){
            st.push(A[i]);
            while(st.size()>0 && st.top()==B[j]){
                st.pop();
                j++;
            }
        }
        if(j==N && st.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
};
