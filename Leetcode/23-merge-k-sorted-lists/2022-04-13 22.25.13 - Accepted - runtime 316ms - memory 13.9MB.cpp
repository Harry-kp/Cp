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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0)return NULL;
        priority_queue<int,vector<int>,greater<int>> pq;
        
        int n = lists.size();
        for(int i = 0;i<n;i++){
            if(lists[i]){
                pq.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
            
        }
        
        for(int i = 0;i<n;i++){
            if(lists[i]){
                pq.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
            
        }
        
        if(pq.empty())return NULL;
        int val = pq.top();
        pq.pop();
        ListNode * head = new ListNode(val,NULL);
        ListNode * tmp = head;
        
        while(!pq.empty()){
            for(int i = 0;i<n;i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]->val);
                // cout<<lists[i]->val<<'\n';
                lists[i] = lists[i]->next;
                }
            }
            
            int val = pq.top();
            // cout<<val<<'\n';
            pq.pop();
            ListNode * node = new ListNode(val,NULL);
            tmp->next = node;
            tmp = tmp->next;
        }
        return head;
    }
};