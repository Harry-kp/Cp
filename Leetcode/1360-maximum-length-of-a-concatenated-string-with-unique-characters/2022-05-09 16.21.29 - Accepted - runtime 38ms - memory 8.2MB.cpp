class Solution {
public:
    
    int bits(int n)
    {
    // base case
    if (n == 0)
        return 0;
 
    else
 
        // if last bit set add 1 else add 0
        return (n & 1) + bits(n >> 1);
    }
    
    int maxLength(vector<string>& o_arr) {
        
        //create all subset as n<=16
        vector<string> arr;
        vector<int> marr;
        
        for(int i = 0;i<o_arr.size();i++)
        {
            int m = 0;
            bool ok = true;
            for(auto c:o_arr[i])
            {
                if((m&(1<<(c-'a'))) !=0){
                    ok=false;
                    break;
                }else
                    m|=(1<<(c-'a'));
            }
            if(ok){
                arr.push_back(o_arr[i]);
                marr.push_back(m);
            }
        }
        
        int n = arr.size();
        int ans = 0;
        for(int mask = 0;mask<(1<<n);mask++){
            int uniq=0;
            bool ok = true;
            for(int i = 0;i<n;i++){
                if(mask&(1<<i)){
                    if((uniq&marr[i])!=0)
                    {
                        ok=false;
                        break;
                    }
                    else
                        uniq|=marr[i];
                }   
            }
            if(ok)
                ans = max(ans,bits(uniq));
        }
        return ans;
    }
};