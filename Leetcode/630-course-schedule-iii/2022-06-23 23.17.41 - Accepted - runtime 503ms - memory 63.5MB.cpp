class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](const vector<int>& a,const vector<int>& b){
        return a[1]<b[1];
        });
        
        priority_queue<int> pq;
        
        int t = 0;
        for(auto x:courses){
            if(t+x[0]<=x[1]){
                t+=x[0];
                pq.push(x[0]);
            }else if(!pq.empty() && pq.top()>x[0]){
                t+=x[0]-pq.top();
                pq.pop();
                pq.push(x[0]);
            }
        }
        return pq.size();
    }
};