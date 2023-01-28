class Solution {
public:
    int firstUniqChar(string s) {
        int ans[26] = {0};
        for(int i = 0;i<s.size();i++)
            ans[s[i]-'a']++;
        for(int i = 0;i<s.size();i++){
            if(ans[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};