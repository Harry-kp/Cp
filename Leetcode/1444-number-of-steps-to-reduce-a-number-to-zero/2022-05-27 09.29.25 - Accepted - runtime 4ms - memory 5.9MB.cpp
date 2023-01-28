class Solution {
public:
    int numberOfSteps(int num) {
        int c = 0;
        
        while(num>0){
            c++;
            
            if(num%2==1)num--;
            else num/=2;
        }
        return c;
    }
};