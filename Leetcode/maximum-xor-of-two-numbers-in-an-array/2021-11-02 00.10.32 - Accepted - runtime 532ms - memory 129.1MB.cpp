class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        vector<vector<int>> trie(1,{0,0});
    vector<bool> terminal(1);

     int N = 0;

    for(auto n:nums){
        int node = 0;
        for(int c = 30;c>=0;c--){
            int bit = ((1<<c)&n)?1:0;
           if(trie[node][bit]==0){
               trie.push_back({0,0});
               terminal.push_back(false);
               trie[node][bit] = ++N;
           }
           node = trie[node][bit];
        }
        terminal[node] = true;
    }


    int ans = 0;
    for(auto x:nums){
        int node = 0;
        int y = 0;
        for(int c = 30;c>=0;c--){
            int bit = ((1<<c)&x)?1:0;
           if(bit == 1){
               if(trie[node][0]!=0){
                   y = (y|(1<<c));
                   node = trie[node][0];
               }else
                    node = trie[node][1];
           }else{
               if(trie[node][1]!=0){
                    y = (y|(1<<c));
                    node = trie[node][1];
               }else
                    node = trie[node][0];
           }
           
    }
    
    ans = max(ans,y);
}
return ans;
    }
};