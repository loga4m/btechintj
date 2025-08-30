class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table {};

        for (int i = 0; i < nums.size(); i++) {
            int j_num = target - nums.at(i);
            if (table.find(j_num) != table.end()) {
                return {i, table.at(j_num)};
            }
            table.insert({nums.at(i), i});
        }
        return {};
    }
};

/*
Time complexity:
    loop -- O(n) (if no target is found or 
                  a part of pair is on the
                  extreme end)

    unordered_map::find,insert -- O(1) average

Space complexity:
    table -- O(n) -> solution at extremes
*/