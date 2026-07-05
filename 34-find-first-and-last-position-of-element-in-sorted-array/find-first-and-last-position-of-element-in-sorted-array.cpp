class Solution {
public:
    int solve_right(vector<int>& nums,int target,int n){
        int possright=-1;
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                possright=mid;
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return possright;
    }
    int solve_left(vector<int>& nums,int target,int n){
        int possleft=-1;
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                possleft=mid;
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return possleft;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int leftwala=solve_left(nums,target,n);
        int rightwala=solve_right(nums,target,n);

        return {leftwala,rightwala};
    }
};