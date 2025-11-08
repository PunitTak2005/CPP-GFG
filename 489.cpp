class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        if n == 0:
            return 0
        res = n
        while n > 0:
            n >>= 1
            res ^= n
        return res
