class Solution {
public:

    void swap(int *a,int *b)
    {
        int c;
        c=*a;
        *a=*b;
        *b=c;
        return;
    }

    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int zeroes=0,ones=0,twos=n-1;


        while(ones<n && ones <= twos)
        {
            if(A[ones]==0)
            {
                swap(&A[ones],&A[zeroes]);
                zeroes++;
                ones++;
            }
            else if(A[ones]==1)
            {
                ones++;
            }
            else if(A[ones]==2)
            {
                swap(&A[ones],&A[twos]);
                twos--;
            }
        }
        return;

    }
};
