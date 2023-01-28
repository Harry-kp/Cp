class Solution {
public:
    int area(int x1,int y1,int x2,int y2){
        printf("%d %d %d %d\n",x1,y1,x2,y2);
        return abs(x2-x1)*abs(y2-y1);
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int int_x =  min(ax2,bx2) - max(ax1,bx1);
        int int_y =  min(ay2,by2) - max(ay1,by1);

        int m = area(ax1,ay1,ax2,ay2) + area(bx1,by1,bx2,by2);

        if(int_x>0 and int_y>0)
            m-= (int_x*int_y);
        return m;
    }
};