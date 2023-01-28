class Solution {
public:
    int firstUniqChar(string s) {
        int ind = 1000000,curr_ind;
        
        int cnt;
        for(int i = 0;i<26;i++){
            cnt = 0;
            for(int j = 0;j<s.size();j++){
                if(s[j]-'a' == i){
                    cnt++;
                    curr_ind = j;
                }
            }
            if(cnt == 1)
                ind = min(ind,curr_ind);
        }
        return ind;
    }
};