class Solution {
  public:
    Node* reverse(Node* head){
        // base case
        if(!head) return head;
        
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;
        
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    Node *compute(Node *head) {
        // code here
        if(!head) return head;
        
        // reverse the head
        head = reverse(head);
        
        int maxi = head->data;
        
        // define the pointers
        Node* curr = head->next;
        Node* temp = head;
        
        while(curr){
            if(curr->data >= maxi){
                maxi = curr->data;
                temp->next = curr;
                temp = temp->next;
            }
            curr = curr->next;
        }
        
        head = reverse(head);
        return temp;
    }
};
