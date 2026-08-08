// Approach 1
// class Solution {
// public:
//     string reverseWords(string s) {
//        stringstream SS(s);
//        string token="";
//        string result="";

//        while(SS >> token){
//         result=token+ " "+ result;
//        }
//        int n=result.length();
//        return result.substr(0,n-1);
//     }
// };


// Approach 2
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
    int n=s.length();
    int l=0,r=0;
    int i=0;
    while(i<n){
        while(i<n && s[i]!=' '){
            s[r]=s[i];
            r++;
            i++;
        }
        if(l<r){
            reverse(s.begin()+l,s.begin()+r);
            s[r]=' ';
            r++;
            l=r;
        }
        i++;
    }
    s=s.substr(0,r-1);
    return s;
    }
};