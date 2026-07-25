class Solution {
public:
    int maxProduct(int n) {
        vector<int> in;
        while(n>0){
            int ones=n%10;
            in.push_back(ones);
            n=n/10;
        }
        sort(in.begin(),in.end());
        int m=in.size();
        return in[m-1]*in[m-2];
    }
};