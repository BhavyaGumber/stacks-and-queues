class Solution {
   
  public:
   int maxi=0;
    int findMaxLen(string s) {
        // code here
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len = i-st.top();
                     maxi = max(maxi,len);
                }
            }
        }
        return maxi;
    }
};
