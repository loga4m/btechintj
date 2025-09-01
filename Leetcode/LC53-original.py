"""
Algorithm
    There are 3 cases:
    1. Sum is negative.
        In this case, we should check whether to reset.
        If the current number is greater, we reset.
    2. Current number is non-negative.
        We always add.
    3. Current number is negative.
        In this case, we add iff:
            current number + sum >= 0. Since this won't
            contribute negative to the next number.

            Before adding, we update max sum.
    4. Current number is negative and the addition arises
       negative contribution. In this case, we update max
       sum and set sum to current number (this will be 
       replaced with next greater one).

    Edge cases:
        1) What if current number is negative and is not
        add-able?
            Then, it will be chosen for sum reset. In the
            next iteration, if an element is again negative,
                a) if it is greater than the sum, reset.
                b) otherwise, two negatives create negative
                contribution. Thus, we won't consider for
                addition either. Thus, reset.
            After these two cases, the next iterations
            either are the same or have greater element
            for reset/extend.
        
"""
class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        size: int = len(nums)
        if size == 1: return nums[0]

        current_sum: int = nums[0]
        max_sum: int = current_sum

        for i in range(1, size):
            ni = nums[i]

            if current_sum < 0 and ni >= current_sum:
                current_sum = ni
                continue

            if ni >= 0:
                current_sum += ni
                continue

            if ni < 0:
                if i < size - 1 and ni + current_sum >= 0:
                    max_sum = max(max_sum, current_sum)
                    current_sum += ni
                    continue
            max_sum = max(max_sum, current_sum)
            current_sum = ni
        
        max_sum = max(max_sum, current_sum)

        return max_sum
    

"""
Time complexity:
    loop -- O(n)

Space complexity:
    loop -- O(1)
"""