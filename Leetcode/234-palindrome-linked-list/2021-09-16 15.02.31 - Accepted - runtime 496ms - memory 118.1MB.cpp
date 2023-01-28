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
        
        while(head){
            tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
    bool compare(ListNode * head1,ListNode * head2){
        bool ans = true;
        
        while(head1){
            // cout<<head1->val<<" "<<head2->val<<'\n';
            if(head1->val != head2->val)ans = false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return ans;
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode * slow = head,*fast = head,*prev,*mid = NULL;
        
        bool ans = true;
        
        if(head and head->next){
            
            while(fast and fast->next){
                fast = fast->next->next;
                prev = slow;
                slow =slow->next;
            }
            
            //len is odd, then fast does not become NULL and we have to store mid node separate
            if(fast != NULL){
                mid = slow;
                slow = slow->next;
            }
            
            prev->next = NULL;
            
            ListNode *second = slow;
            
            second = reverse(second);
            // cout<<(second->val);
            ans = compare(head,second);
            second = reverse(second);
            
            if(mid!=NULL){
                prev->next = mid;
                mid->next = second;
            }else{
                prev->next= second;
            }
            
        }
        
        // while(head){
        //     // cout<<head->val<<" ";
        //     head = head->next;
        // }
        return ans;
        
        
    }
};