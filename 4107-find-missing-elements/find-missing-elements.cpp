class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int mini=nums[0];
        int maxi=nums[nums.size()-1];
        int count=mini;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==count){
                count=count+1;
                i++;
            }
            else{
                ans.push_back(count);
                count=count+1;
            }
        }    
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==count){
        //         count=count+1;
        //     }
        //     else{
        //         ans.push_back(count);
        //         count=count+1;
        //     }
        // }
        return ans;
    }
};