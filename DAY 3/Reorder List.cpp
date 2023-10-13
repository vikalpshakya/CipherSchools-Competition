class Solution {
public:

// ---Time complexity: O(n), Space complexity: O(1) [Ignoring space used by recursive stack]-----

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* secondLast = head;
        while (secondLast->next->next) {
            secondLast = secondLast->next;
        }
        ListNode* last = secondLast->next;
        secondLast->next = nullptr;
        ListNode* next = head->next;
        head->next = last;
        last->next = next;


        reorderList(next);
    }

};
