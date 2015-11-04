class Solution {
public:

    void helper(int n,int k,vector<int> combine, vector<vector<int> > &result,int i)
    {
        if(k==0)
            result.push_back(combine);
        if(i>n)
            return;
        int j;
        for(j=i;j<=n;j++)
        {
            combine.push_back(j);
            helper(n,k-1,combine,result,j+1);
            combine.pop_back();
        }
        return;

    }

    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> combine;
        vector<vector <int> > result;
        helper(n,k,combine,result,1);
        return result;
    }
};
