class Solution {
public:
    string reverseWords(string s) {
       stringstream SS(s);
       string token="";
       string result="";

       while(SS >> token){
        result=token+ " "+ result;
       }
       int n=result.length();
       return result.substr(0,n-1);
    }
};