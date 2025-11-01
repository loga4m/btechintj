class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> indexMap;
        vector<string> answer(score.size());
        priority_queue<int> sp;
        
        for (int i = 0;  i < score.size(); i++) {
            indexMap[score[i]] = i;
            sp.push(score[i]);
        }

        int rank = 1;
        while (!sp.empty()) {
            int top = sp.top();
            sp.pop();
            int index = indexMap[top];

            if (rank == 1) {
                answer[index] = "Gold Medal";
            }
            else if (rank == 2) {
                answer[index] = "Silver Medal";
            }
            else if (rank == 3) {
                answer[index] = "Bronze Medal";
            }
            else {
                answer[index] = to_string(rank);
            }
            rank++;
        }

        return answer;
    }
};

