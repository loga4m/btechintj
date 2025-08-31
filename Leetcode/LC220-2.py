class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        buckets = {}

        for i in range(0, len(nums)):
            if i > indexDiff:
                removal_bucket_id = nums[i - indexDiff - 1] // (valueDiff + 1)
                del buckets[removal_bucket_id]

            bucket_id = nums[i] // (valueDiff + 1)

            if bucket_id in buckets:
                return True

            next_adjacent = bucket_id + 1
            prev_adjacent = bucket_id -1

            for adjacent_id in [next_adjacent, prev_adjacent]:
                if adjacent_id in buckets and \
                    abs(buckets[adjacent_id] - nums[i]) <= valueDiff:
                        return True
            buckets[bucket_id] = nums[i]
        return False

"""
My explanation on bucket_id = n // (valueDiff + 1):

Take a number n and the difference k.
Do integer division n/k.
You will have integers on range [0, n]
get grouped by k elements each. On this range,
it is obvious that k belongs [0, n].

Then, since we group by at most k,
[0, k - 1] gives us k number elements. 
I subtract - 1 because we start from zero.
If we started from one, we could count
first k elements that end with k.

Now, the generic interval becomes:
    [z*k, (z + 1) * k - 1], where z is integer.
(
    derivation: first interval obviously is [0, k - 1], 
    the next starts with k. 
    Then, to contain another k elements, we add k. 
    But it will count k elements starting from k + 1. 
    Thus, we subtract 1 to exclude excess and make the 
    k element inclusive. Now, we can generalize this 
    by putting a coefficient that means the zth container (bucket)
).

Then, the difference between extremes is:

(z + 1) * k - 1 - zk = zk + k - 1 - zk = k - 1 < k.
This proves we are getting max difference off by one from k.

Now, start with n / k + 1.
You will have integers on range [0, k] (first k integers and 0). Then,
based on the previous result, the generic interval is: 
    [z(k + 1), (z+1)(k + 1) - 1], where z is integer.

Then, the diff between ends is:
zk + z + k + 1 - 1 - (zk + z) = k + 1 - 1 = k.

Because the range is sorted, the elements on 
    (z(k+1), (z+1)(k+1) - 1) 
will always have smaller difference.
Therefore, the difference will be <= k.

Another point is that, if we denote k or 
k + 1 as group_size, our range will never 
contain a group whose size is greater than group_size.

Proof.

If we have generic [zgroup_size, (z+1)group_size - 1] 
and the size of the interval [(z+1)group_size, n] is 
x*group_size + excess, this range can further be 
divided by group_size and result in 
    x + excess/group_size. 
So, we end up with another x times group_size and 
excess/group_size < group_size will always be true (excess < group_size^2).
Therefore, group_size is at most group_size.
"""
