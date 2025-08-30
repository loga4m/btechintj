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

