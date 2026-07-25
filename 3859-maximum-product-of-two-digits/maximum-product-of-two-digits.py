class Solution(object):
    def maxProduct(self, n):
        first, second = -1, -1
        while n>0:
            d=n%10
            if d>first:
                second=first
                first=d
            elif d>second:
                second=d
            n//=10
        return first * second
        