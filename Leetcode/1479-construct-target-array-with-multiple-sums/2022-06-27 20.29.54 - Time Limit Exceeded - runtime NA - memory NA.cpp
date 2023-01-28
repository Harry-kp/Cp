class Solution {
public:
    bool isPossible(vector<int>& t) {
        priority_queue<int> pq;
        
        int s = 0;
        for(auto x:t){
            pq.push(x);
            s+=x;
        }
        
       while(1){
           if(pq.top() == 1)return true;
           int pre = 2*pq.top()-s;
           if(pre<1)break;
           
           s-=pq.top();
           s+=pre;
           pq.pop();
           pq.push(pre);
       }
        return false;
    }
};