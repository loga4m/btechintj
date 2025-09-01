"""
Algorithm
    This compact solution collapses the whole 4(5) 
    cases handling in the original solution (LC53-original.py).

    I restate the cases and show that all cases are satisfied.

    1) Sum is negative. If current num is greater, reset.

            In this solution, the num is taken regardless,
            since current_num + num <= num is always true
            for current_num < 0.
            This means a reset.

            One may aks: if current_num was smaller,
            we're losing the its value here, and we haven't
            saved it, and thus won't it get missed?
            Answer is no, since shortly after max_sum compares
            its previous state (this ensures the thing is not
            missed!) and thus gets the correct thing.

            Therefore, this compact logic collapses two handlers
            into one.

    2) Current number is non-negative. Then add.
        Obviously, if current number is non-negative, then
        sum is always greater if current sum >= 0. If current_sum
        is negative, the reset happens.

        So, this matches:
            1) when current_sum < 0, the original algorithm's
               1st case.
            2) otherwise, the orginal algorithm's 2nd case.
    
    3) If current number is negative.
        If so, we only add when sum results in 0 or greater.
        If true, we first save max_sum.

        The current solution encomppasess the 1st case and
        the positive contribution case into one.

        If current_sum < 0, the 1st case reset. Otherwise,
        max(total_sum, num). Even if this results in negative
        contibution, the next number will fall to 1st case and
        reset happens.
        If contribution is not negative, it is okay.

    4) If negative contribution, reset.
        This is clearly handled in the 3rd step. 

"""
class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        current_sum: int = nums[0]
        max_sum: int = current_sum

        for num in nums[1:]:
            current_sum = max(num, current_sum + num)
            max_sum = max(max_sum, current_sum)

        return max_sum
    

"""
Time complexity:
    loop -- O(n)

Space complexity:
    loop -- O(1)
"""