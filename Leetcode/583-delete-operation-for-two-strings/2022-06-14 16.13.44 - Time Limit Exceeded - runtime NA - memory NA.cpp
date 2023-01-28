class Solution {
public:
    int solve(int l,int r,const string& s1,const string& s2){
        if(l>=s1.size() or r>=s2.size())
            return 0;
        
        if(s1[l]!=s2[r])
            return max(solve(l+1,r,s1,s2),solve(l,r+1,s1,s2));
        return 1+solve(l+1,r+1,s1,s2);
    }
    int minDistance(string word1, string word2) {
        return word1.size()+word2.size()-2*solve(0,0,word1,word2);
    }
};