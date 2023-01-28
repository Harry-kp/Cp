class Solution {
public:
    bool isPossible(vector<int>& t) {
        priority_queue<int> pq;
        if(t.size() == 1)return t[0] == 1?true:false;
        int s = 0;
        for(auto x:t){
            pq.push(x);
            s+=x;
        }
        
       while(pq.top()!=1){
           int cur = pq.top();
           if(s-cur == 1)return true;
           int x = cur%(s - cur);
           
           if(x == 0 or x == cur)return false;
           s = s-cur + x;
           pq.pop();
           pq.push(x);
       }
        return true;
    }
};