
class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
         n=len(nums)
         t=[[0]*2 for _ in range(n+1)]

         for i in range(1,n+1):
            t[i][0]=max(t[i-1][1]-nums[i-1],t[i-1][0])

            t[i][1]=max(t[i-1][0]+nums[i-1],t[i-1][1])

         return max(t[n][0],t[n][1])
