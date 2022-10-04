class Solution {
public:
    int maxLength(vector<string>& arr) {
        
        //create all subset as n<=16
        int n = arr.size();
        int ans = 0;
        for(int mask = 0;mask<(1<<n);mask++){
            unordered_set<char> st;
            bool ok = true;
            for(int i = 0;i<n;i++){
                if(mask&(1<<i)){
                    for(auto c:arr[i]){
                        if(st.count(c))
                        {
                            ok=false;
                            break;
                        }
                        st.insert(c);
                    }
                }   
            }
            if(ok)
                ans = max(ans,(int)st.size());
        }
        return ans;
    }
};