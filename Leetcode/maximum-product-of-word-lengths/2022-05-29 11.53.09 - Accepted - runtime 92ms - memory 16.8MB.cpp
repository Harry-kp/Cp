class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bit;
        int n = words.size();
        for(auto w:words){
            int a = 0;
            
            for(int i = 0;i<w.size();i++){
                a|=(1<<(w[i]-'a'));
            }
            bit.push_back(a);
        }
        int mx = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if((bit[i]&bit[j])==0)
                    mx = max(mx,(int)words[i].size()*(int)words[j].size());
            }
        }
        return mx;
    }
};