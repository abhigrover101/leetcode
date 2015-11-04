class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 2;


        int p2=1,p1=2,c=0,i=3;
        while(i<=n)
        {
            c=p1+p2;
            p2=p1;
            p1=c;
            i++;
        }

        return c;
    }
};
