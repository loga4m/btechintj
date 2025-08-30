class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> table {};

        for (int i = 0; i < nums.size(); i++) {
            int num = nums.at(i);
            if (table.find(num) != table.end() ) {
                if (abs(i - table.at(num)) <= k) return true;
                table.at(num) = i;
                continue;
            }
            table.insert({num, i});            
        }
        return false;
    }
};

/*
Time complexity:
    loop -- O(n), if no solution is found
    unordered_map::insert, at -- 
        O(1), O(k) if hash collisions occur,
        where k <= n.
        We treat it as amortized.

    Overall: O(n)

Space complexity:
    unordered_map -- O(n) -- if not solution is found
    loop -- O(1)

    Overall: O(n)
*/