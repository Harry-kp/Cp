class Solution {
public:
    bool check(string a, string b){
        int same = 0;
        for(int i = 0;i<8;i++)
            if(a[i] != b[i])
                same++;
        return same == 1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        bank.push_back(start);
        bank.push_back(end);
        
        int n = bank.size();
        int dist[n][n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++)
                if(i == j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = check(bank[i],bank[j]) ? 1 : 100000000;
        }    
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++)
                for(int k = 0;k<n;k++)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }
        return dist[n-2][n-1] == 100000000 ? -1:dist[n-2][n-1];
    }
};