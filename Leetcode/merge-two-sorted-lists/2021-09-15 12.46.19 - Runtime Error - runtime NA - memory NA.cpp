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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode * head = NULL,*tmp;
        while(l1 and l2){
            if(l1->val<=l2->val){
                if(head == NULL)head = l1;
                tmp = l1;
                l1 = l1->next;
                tmp->next = l2;
                }
            else{
                if(head == NULL)head = l2;
                tmp = l2;
                l2 = l2->next;
                tmp->next = l1;
            }
        }
        
        if(l1!=NULL)
            tmp->next = l1;
        if(l2!=NULL)
            tmp->next = l2;
        return head;
        }
};