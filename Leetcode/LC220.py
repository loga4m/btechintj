class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        tracker = [nums[0]]

        for i in range(1, len(nums)):
            if i > indexDiff:
                tracker.remove(nums[i - indexDiff - 1])
            
            if len(tracker) == 0:
                tracker.append(nums[i])
                continue # since no element to compare
                
            insert_inx = self.bisect(tracker, nums[i])
            tracker.insert(insert_inx, nums[i])

            if insert_inx > 0:
                prev = tracker[insert_inx - 1]
                if abs(nums[i] - prev) <= valueDiff:
                    return True
            
            if insert_inx < len(tracker) - 1:
                next_ = tracker[insert_inx + 1]
                if abs(nums[i] - next_) <= valueDiff:
                    return True

        return False

    def bisect(self, source: list[int], value: int) -> int:
        if len(source) == 1:
            index = 1 if source[0] < value else 0
            return index
        low = 0
        high = len(source) - 1

        while (low < high):
            mid = (low + high) // 2

            if value > source[mid]:
                low = mid + 1
            else:
                high = mid - 1
        
        return low + 1 if value > source[low] else low

"""
Time complexity:
    loop inner -- 
        tracker.remove(value) -- O(indexDiff) (but not the case when indexDiff == nums.length)
        tracker.insert(value) -- O(indexDiff)
        bisect(source, value) -- O(logn)
        Total: O(2*indexDiff + logn)
    
    loop outer -- O(n)
        With inner: O(2n*indexDiff + 2nlogn) = O(n^2) (given indexDiff is very near to nums.length)

    This calculation is approximate.
    However, the solution with two degree loops failed the tests and it was O(n^2).
    Therefore, this algorithm took less than it, which means the upper bound Big O
    is no higher than O(n^2).
"""