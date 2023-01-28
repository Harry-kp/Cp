class Solution {
public:
    unordered_map<int, vector<int>> map;
    bool flag = false;
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if(start == end) return true;
        vector<int> visit(n, 0);
        for(auto e: edges)
        {
            map[e[0]].push_back(e[1]);
            map[e[1]].push_back(e[0]);
        }
        return bfs(start, end, visit);
    }
    
    bool bfs(int start, int target, vector<int>& visit)
    {
        visit[start] = 1;
        if(find(map[start].begin(), map[start].end(), target) != map[start].end()) flag = true;
        for(int m: map[start])
            if(!flag && visit[m] == 0) bfs(m, target, visit);
        return flag;
    }
};