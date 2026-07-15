
// Approach 1: Rec+Memo
// class Solution {
// public:
// long long t[100001][2];
//     long long solve(long long idx,vector<int>& nums, bool flag){
//         long long n=nums.size();
//         if(idx>=n){
//             return 0;
//         }
//         if(t[idx][flag]!=-1){
//             return t[idx][flag];
//         }
//         long long skip=solve(idx+1,nums,flag);
//         long long value=nums[idx];
//         if(flag==false){
//             value=-value;
//         }
//         long long take=value+ solve(idx+1,nums,!flag);

//         return t[idx][flag]=max(skip,take);
//     }

//     long long maxAlternatingSum(vector<int>& nums) {
//         memset(t,-1,sizeof(t));
//         return solve(0,nums,true);
//     }
// };

// Approach 2:Bottom-Up

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();

        vector<vector< long long>> t(n+1,vector< long long>(2,0));

        for(int i=1;i<n+1;i++){
            t[i][0]=max((t[i-1][1]-nums[i-1]), t[i-1][0]);
            t[i][1]=max((t[i-1][0]+nums[i-1]),t[i-1][1]);
        }
        return max(t[n][0],t[n][1]);
    }
};