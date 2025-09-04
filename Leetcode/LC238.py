class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        size: int = len(nums)
        prefix: int = [0 for i in range(len(nums))]
        suffix: int = [0 for i in range(len(nums))]

        i: int = 0
        j: int = len(nums) - 1
        pre: int = 1
        suff: int = 1

        while i < size - 1 and j >= 0:
            prefix[i] = pre
            pre *= nums[i]

            suffix[j] = suff
            suff *= nums[j]

        for k in range(len(nums)):
            nums[i] = prefix[k] * suffix[k]
        
        return nums

"""
Time complexity:
    Four loops of n -- O(4n) = O(n)
    Since there is no early exit,
    this is Theta(n)
    
    Overall: O(n)
Space complexity:
    Two lists -- O(2n)
    Variables -- O(1)
    New nums -- in-place, O(1)

    Overall: O(n)
"""