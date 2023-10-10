class Solution {
public:

// ----------Time complexity: O(N), Space complexity: O(1) ------------//

    int numComponents(ListNode* head, vector<int>& nums) {
        int ans = 0, count1 = 0;
        ListNode* temp = head;
        while(temp){  
            if(count(nums.begin(),nums.end(),temp->val) == 1){
                count1++;
                if(count1 == 1)
                   ans++ ;
            }
            else    
                count1 = 0;
            temp = temp->next;
        }
        return ans;
    }
};
