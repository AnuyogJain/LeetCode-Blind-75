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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        
        ListNode* temp = new ListNode();
        ListNode* ans = temp;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        
        if (list1)
            temp->next = list1;
        
        if (list2)
            temp->next = list2;
        
        return ans->next;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() < 1)
            return NULL;
        if(lists.size() < 2)
            return lists[0];
        
        //merging 2 lists and storing them till only 1 list left
        while (lists.size() > 1) {
            vector<ListNode*> temp;
            
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1) < lists.size() ? lists[i + 1] : NULL;
                
                temp.push_back(mergeTwoLists(l1, l2));
            }
            
            lists = temp;
        }
        
        
        return lists[0];
    }
};
