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
    ListNode * reverse(ListNode * head){
        if(!head or !head->next)return head;
        
        ListNode * prev = NULL,*tmp;
        
        while(head->next){
            tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        
        return head;
    }
    
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head,*fast = head;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = NULL;
        //palindrone lenght is odd
        if(fast == NULL){
            mid = slow;
            slow = slow->next;
        }
        
        ListNode * first = head;
        ListNode * second = reverse(slow);
        ListNode * tmp = second;
        
        bool ans = true;
        while(second){
            if(second->val != first->val)
                ans = false;
            first = first->next;
            second = second->next;
        }
        
        second = reverse(tmp);
        if(mid){
            first->next = mid;
            mid->next = second;
        }else{
            first->next = second;
}
        return ans;
        
            
    }
};