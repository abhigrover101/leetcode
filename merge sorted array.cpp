class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int j=m-1,i=0,k=0;
        for(i=m+n-1;i>=n;i--)
            A[i]=A[j--];

        i=0;j=n;
        while(i<m+n)
        {
            if(A[j]<B[k] && j<m+n)
            {
                A[i++]=A[j++];
            }
            else if(k<n)
            {
                A[i++]=B[k++];
            }
            if(k==n && j<m+n)
            {
                A[i++]=A[j++];
            }
            if(j==m+n && k<n)
            {
                A[i++]=B[k++];
            }
        }
    }
};
