class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen {}; // or use set

        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(nums.at(i)) != seen.end()) return true;
            seen.insert({nums.at(i), 1}); // in set: seen.insert(val)
        }
        return false;
    }
};

/*
Time complexity:
    loop -- O(n) -- if all nums are unique, full traversal
    others -- O(1), overhead

    Overall: O(n)

Space complexity:
    unordered_map(or set) -- O(n) if all nums are unique

    Overall: O(n)
*/