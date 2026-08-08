class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(s[i]==')'  && st.size()==1){
                st.pop();

            }
            else if(s[i]=='('){
                st.push(s[i]);
                 ans.push_back(s[i]);
            }
            else{
                
                st.pop();
                
                ans.push_back(s[i]);
            }
        }
        return ans;
        
    }
};