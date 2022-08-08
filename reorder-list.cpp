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
    ListNode* findMiddle(ListNode* head) {
        if (!head)
            return NULL;
        
        ListNode* temp;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        temp->next = NULL;
        
        return slow;
    }
    
    ListNode* reverse(ListNode* head) {
        if (!head)
            return NULL;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;
        
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    void merge(ListNode* head1, ListNode* head2) {
        while (head1) {
            //store both next element in a new node
            ListNode* temp1 = head1->next;
            ListNode* temp2 = head2->next;
            
            //connect both of them
            head1->next = head2;
            
            if (!temp1)
                return;
            
            head2->next = temp1;
            
            head1 = temp1;
            head2 = temp2;
        }
    }
    
    void reorderList(ListNode* head) {
        if (!head->next)
            return;
        
        ListNode* middle = findMiddle(head);
        ListNode* reversed = reverse(middle);
        merge(head, reversed);
    }
};
