class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        size: int = len(nums)
        prefix: int = [0 for i in range(len(nums))]

        i: int = 0
        j: int = len(nums) - 1
        pre: int = 1

        while i < size - 1 and j >= 0:
            prefix[i] = pre
            pre *= nums[i]

        suff: int = 1

        for k in range(len(nums), -1, -1):
            nums[i] = prefix[k] * suff
            suff *= nums[k]
        
        return nums

"""
Time complexity:
    Four loops of n -- O(3n) = O(n)
    Since there is no early exit,
    this is Theta(n)
    
    Overall: O(n)
Space complexity:
    One list -- O(n)
    Variables -- O(1)
    New nums -- in-place, O(1)

    Overall: O(n)
"""