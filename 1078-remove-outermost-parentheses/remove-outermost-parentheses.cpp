// #Appproach 1

// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         stack<char> st;
//         string ans="";
//         for(int i=0;i<s.length();i++){
//             if(st.empty()){
//                 st.push(s[i]);

//             }
//         else if(st.size()==1 && s[i]==')'){
//             st.pop();
//         }
//         else if(s[i]==')'){
//             st.pop();
//             ans.push_back(s[i]);
//         }
//         else{
//             st.push(s[i]);
//             ans.push_back(s[i]);
//         }
//         }
//         return ans;
        
//     }
// };

// #Approach 2


class Solution {
public:
    string removeOuterParentheses(string s) {
        int counter=0;        
        string ans="";
        for(int i=0;i<s.length();i++){
           if( s[i]=='(' ){
            if(counter>0){
            ans.push_back(s[i]);}
            counter++;
           }
           else {
            counter--;
                 if(counter>0){
                ans.push_back(s[i]);}
           
           
        }
        }
        return ans;
        
    }
};
