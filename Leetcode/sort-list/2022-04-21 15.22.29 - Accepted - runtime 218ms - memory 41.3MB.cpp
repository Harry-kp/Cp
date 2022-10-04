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
    ListNode* merge2List(ListNode*a,ListNode*b){
        ListNode*result = NULL;
        if(a == NULL)
            return b;
        if(b==NULL)
            return a;
        
        if(a->val<b->val){
            result = a;
            result->next = merge2List(a->next,b);
        }
        else{
            result = b;
            result->next = merge2List(a,b->next);
        }
        return result;
    }
    
    ListNode* mergeSort(ListNode * ls){
        if(ls == NULL or ls->next == NULL)return ls;
        
        ListNode* fast = ls;
        ListNode* slow = ls;
        ListNode*temp = NULL;
        
        while(fast!=NULL and fast->next!=NULL){
            temp=slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next=NULL;
        ListNode* a = mergeSort(ls);
        ListNode*b = mergeSort(slow);
            
        return merge2List(a,b);
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL or head->next == NULL)return head;
        return mergeSort(head);
    }
};