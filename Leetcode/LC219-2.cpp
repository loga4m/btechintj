class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> seen {};

        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                seen.erase(nums.at(i - k - 1)); // remove element at
                                                // out of the interval
            }
            int num = nums.at(i);
            if (seen.find(num) != seen.end()) return true;
            seen.insert(num);
        }
        return false;
    }
};

/*
Algorithm explanation:
    Core Idea: track the zone of potential solution.
    The i > k block works to remove an element
    which is out of zone ([i - k, i]).

    Otherwise, the logic is the same as of hash table.

Time complexity:
    loop -- O(n), if no solution is found
    erase by value --
        O(logn), because according
        to Google search overview,
        set is implement as Self-Balanced BST
    set::insert
        O(logn), for the same reasons
    set::find
        O(logn), for the same reasons

    Overall: O(n)

Space complexity:
    set -- O(n), if no solution is found

    Overall: O(n)
*/