class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> next_smaller(n),prev_smaller(n);

        stack<int> s1;
        for(int i = 0;i<n;i++){
            next_smaller[i] = n-i-1;
            prev_smaller[i] = i;
        }

        for(int i = 0;i<n;i++){
            while(!s1.empty() and arr[s1.top()]>arr[i]){
                next_smaller[s1.top()] = i-s1.top()-1;
                s1.pop();}
            s1.push(i);
        }
        while(!s1.empty())s1.pop();
        for(int i = n-1;i>=0;i--){
            while(!s1.empty() and arr[s1.top()]>=arr[i]){
                prev_smaller[s1.top()] = s1.top()-i-1;
                s1.pop();}
            s1.push(i);
        }
        int mod = 1000000007;
        long long int ans = 0;
        for(int i = 0;i<n;i++){
            ans += (arr[i]*(next_smaller[i]+1)%mod*(prev_smaller[i]+1)%mod);
            ans%=mod;
        }
        return ans;
    }
};