 class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for(char bracket:s){
            if(bracket=='(' || bracket=='{' || bracket=='['){
                brackets.push(bracket);
            }else{
                if(bracket==')'){
                    if(brackets.empty() || brackets.top()!='(') return false;
                }else if(bracket=='}'){
                    if(brackets.empty() || brackets.top()!='{') return false;
                }else{
                    if(brackets.empty() || brackets.top()!='[') return false;
                }
                brackets.pop();
            }
        }
        if(!brackets.empty()) return false;
        return true;
        
        
    }
};
