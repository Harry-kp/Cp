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
    ListNode* merge2List(ListNode*&a,ListNode*&b){
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
    
    ListNode * mergeKList(vector<ListNode*>& lists,int last){
        while(last!=0){
            int i = 0;
            int j = last;
            
            while(i<j){
                lists[i] = merge2List(lists[i],lists[j]);
                i++;j--;
                
                if(i>=j)
                    last=j;
            }
            
        }
        return lists[0];
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return mergeKList(lists,n-1);
    }
};