class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long long> next_smaller(n),prev_smaller(n);

        stack<long long> s1;
        for(long long i = 0;i<n;i++){
            next_smaller[i] = n-i-1;
            prev_smaller[i] = i;
        }

        for(long long i = 0;i<n;i++){
            while(!s1.empty() and arr[s1.top()]>arr[i]){
                next_smaller[s1.top()] = i-s1.top()-1;
                s1.pop();}
            s1.push(i);
        }
        while(!s1.empty())s1.pop();
        for(long long i = n-1;i>=0;i--){
            while(!s1.empty() and arr[s1.top()]>=arr[i]){
                prev_smaller[s1.top()] = s1.top()-i-1;
                s1.pop();}
            s1.push(i);
        }
        long long mod = 1e9+7;
        long long  ans = 0;
        for(long long i = 0;i<n;i++){
            long long tmp  = (next_smaller[i]+1)*(prev_smaller[i]+1);
            tmp%-mod;
            ans += (arr[i]*tmp);
            ans%=mod;
        }
        return ans;
    }
};