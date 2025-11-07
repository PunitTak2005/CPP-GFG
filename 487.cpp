class Solution:
    def maxPower(self, stations, r, k):
        n = len(stations)
        
        def isPossible(minPower):
            add = [0] * n
            totalAdd = 0
            curr = sum(stations[:r * 2 + 1])
            left, cnt = 0, 0
            
            for i in range(n):
                if i + r < n:
                    if i - r - 1 >= 0:
                        curr -= stations[i - r - 1]
                        curr -= add[i - r - 1]
                if curr < minPower:
                    need = minPower - curr
                    if i + r >= n:
                        pos = n - 1
                    else:
                        pos = i + r
                    add[pos] += need
                    curr += need
                    cnt += need
                if cnt > k: return False
                if i + 1 < n:
                    curr += stations[i + r + 1] if i + r + 1 < n else 0
                    curr += add[i + r + 1] if i + r + 1 < n else 0
                
            return True

        left, right = min(stations), sum(stations) + k
        res = left

        while left <= right:
            mid = (left + right) // 2
            if isPossible(mid):
                res = mid
                left = mid + 1
            else:
                right = mid - 1
        return res
