class Solution {
public:
    
    void shellSort(vector<int>& num,int n){
        int g = n,i,j;
        while(g>1){
            g>>=1;
            i = 0,j = g;
            
            while(j<n){
                if(num[i]>num[j])swap(num[i],num[j]);
                i++;j++;
            }
        }
}
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        
        int i = m,j = 0;
        while(j<n){
            num1[i] = num2[j];
            i++;j++;
        }
        shellSort(num1,m+n);
    }
};