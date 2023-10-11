class Solution{
public:
// ------Time complexity: O(n), Space complexity: O(1) ------ // 

    Node* divide(int N, Node *head){
        Node* evenHead = NULL;
        Node* evenTail = NULL;
        Node* oddHead = NULL;
        Node* oddTail = NULL;
        Node* temp = head;
        
        while(temp != NULL){
            if(temp->data % 2 == 0){
                if(!evenHead){
                    evenHead = temp;
                    evenTail = temp;
                }
                else{
                    evenTail->next = temp;
                    evenTail = evenTail->next;
                }
            }
            else{
                if(!oddHead){
                    oddHead = temp;
                    oddTail = temp;
                }
                else{
                    oddTail->next = temp;
                    oddTail = oddTail->next;
                }
            }
            temp = temp->next;
        }
        
        if(!oddHead){
            return evenHead;
        }
        oddTail->next = NULL;
        
        if(!evenHead){
            return oddHead;
        }
        else{
            evenTail->next = oddHead;
            return evenHead;
        }
    }
};
