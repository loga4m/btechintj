class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i]++; // increment by one
            if (digits[i] < 10) break; // if true, we're done

            if (i == 0) { // if at 0, it means we have a carry
                // from previous digits (num)
                digits[i] = 1;
                digits.push_back(0); // safe as adding one
                // can turn digit to 10 only if a digit is 9.
                break;
            }

            digits[i] = digits[i] % 10; // update with the first digit part
        }
        return digits;
    }
};

/*
Time complexity:
    loop -- O(n)
    push_back -- cppreference.com says amortized constant. O(1)

    Overall: O(n)

Space complexity:
    loop -- O(1)
*/