class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0;

        // Construct prefixGcd in-place
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
            nums[i] = gcd(nums[i], mx);
        }

        // Sort prefixGcd
        sort(nums.begin(), nums.end());

        // Form pairs
        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n / 2; i++) {
            ans += gcd(nums[i], nums[n - 1 - i]);
        }

        return ans;
    }
};