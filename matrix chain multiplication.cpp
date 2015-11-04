#include<cstdio>
#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n,i=0,j=0,d=0,min,k=0,temp=0;
    cout << "Enter n+1 followed by array of numbers\n";
    cin >> n;
    int a[n],dp[n][n];


    for(i=0;i<n;i++)
    {
        cin>>a[i];
        dp[i][i]=0;
    }
    //dp[1][n]=0;

    for(d=1;d<n-1;d++)
    {
        for(i=1;i<=n-d-1;i++)
        {
            k=i+d;
            min=INT_MAX;
            for(j=i;j<k;j++)
            {
                temp=dp[i][j]+dp[j+1][k]+a[i-1]*a[j]*a[k];
                if(temp<min)
                {
                    min=temp;
                }
            }
            dp[i][k]=min;
        }
    }

    cout <<dp[1][n-1];


}
