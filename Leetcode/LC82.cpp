/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = head;
        ListNode* lastDupl = nullptr;

        /*
            Algorithm:
                1) Check if current element is lastDupl. If so,
                   skip.
                2) Check if the next is also the same value.
                    True :=> update lastDupl to current and continue.
                2) Otherwise, link it to lastUnique and update
                   lastUnique to the current Node.      
        */

        // Set head to a unique element
        while (newHead) {
            bool isDupl = (lastDupl && newHead->val == lastDupl->val) ? 1:0;
            if (isDupl) {
                newHead = newHead->next;
                continue;
            }
            if (newHead->next && newHead->next->val == newHead->val) {
                lastDupl = newHead;
                newHead = newHead->next;
                continue;
            }
            break;
        }

        // This means all elements are duplicate.
        if (!newHead) return newHead;

        ListNode* lastUnique = newHead;
        ListNode* mover = newHead->next;

        while (mover) {
            if (lastDupl && mover->val == lastDupl->val) {
                mover = mover->next;
                continue;
            }
            if (mover->next && mover->val == mover->next->val) {
                lastDupl = mover;
                mover = mover->next;
                continue;
            }
            lastUnique->next = mover;
            lastUnique = mover;
            mover = mover->next;
        }
        lastUnique->next = nullptr;
        return newHead;
    }
};
