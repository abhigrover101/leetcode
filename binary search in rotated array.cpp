class Solution {
public:

    int rotate(int A[],int lo,int hi,int target)
    {
        if(hi<lo)
            return -1;

        int mid=lo+(hi-lo)/2;
        if(A[mid]==target)
            return mid;

        if(A[mid] > A[hi])
        {
            if(target < A[mid] && target > A[hi])
                return rotate(A,lo,mid-1,target);
            else
                return rotate(A,mid+1,hi,target);
        }
        else
        {
            if(target > A[mid] && target <= A[hi])
                return rotate(A,mid+1,hi,target);
            else
                return rotate(A,lo,mid-1,target);

        }
        return -1;
    }


    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int mid,lo=0,hi=n-1;

        return rotate(A,lo,hi,target);
    }
};
