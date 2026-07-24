class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        MAXX = 2048

        dp = [[False] * MAXX for _ in range(4)]
        dp[0][0] = True

        # Pick first element
        for x in nums:
            dp[1][x] = True

        # Pick second element
        for v in range(MAXX):
            if dp[1][v]:
                for x in nums:
                    dp[2][v ^ x] = True

        # Pick third element
        for v in range(MAXX):
            if dp[2][v]:
                for x in nums:
                    dp[3][v ^ x] = True

        return sum(dp[3])