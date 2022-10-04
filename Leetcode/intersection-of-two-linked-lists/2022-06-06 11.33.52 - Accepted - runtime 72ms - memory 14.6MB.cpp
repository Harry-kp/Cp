/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int size(ListNode * head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = size(headA);
        int n2 = size(headB);
        
        if(n2>n1){
        swap(headA,headB);
        swap(n1,n2);
        }
        
        for(int i = 0;i<(n1-n2);i++)
            headA = headA->next;
        
        while(headA){
            if(headA == headB)return headA;
            
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};