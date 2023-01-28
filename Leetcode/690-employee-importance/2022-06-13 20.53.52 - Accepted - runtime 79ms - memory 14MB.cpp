/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    void dfs(int id,int& ans, map<int,Employee*>& mp){
        ans+=mp[id]->importance;
            
        
        for(auto x:mp[id]->subordinates){
            dfs(x,ans,mp);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        map<int,Employee*> mp;
        
        for(auto x:employees){
            mp[x->id]=x;
        }
        
        int ans = 0;
        dfs(id,ans,mp);
        return ans;
        
    }
};