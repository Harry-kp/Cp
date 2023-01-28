/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long int l = 0;
        long int r = n;
        long int m,k;
        while(l+1<r){
            m = (l+r)/2;
            k = guess(m);

            if(k <= 0)
                r=m;
            else
                l=m;
        }
        return r;
    }
};