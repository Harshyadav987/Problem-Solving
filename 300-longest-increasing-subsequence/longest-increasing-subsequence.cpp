class Solution {
public:
    int t[2501][2501];
    int solve(int i,int P,vector<int>& nums){
        int n=nums.size();
        int take=0,skip=0;
        if(i>=n){
            return 0;
        }
        if(P!=-1 && t[i][P]!=-1){
            return t[i][P];
        }
        if(P==-1 || nums[P]<nums[i])
         take=1+solve(i+1,i,nums);

         skip=solve(i+1,P,nums);
        
        if(P!=-1)
         t[i][P]= max(take,skip);

         return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,-1,nums);
    }
};