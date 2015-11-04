class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long int left=0,right=x;
        long long int mid=0;
        while(right-left>=1)
        {
            mid=left+(right-left+1)/2;
            if(mid*mid>x)
            {
                right=mid-1;
            }
            else if(mid*mid<x)
            {
                left=mid;
            }
            else
                return mid;
        }
        return left;
    }
};
