class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int si;
        si=triangle.size();
        if(si==1)
            return triangle[0][0];

        for(int i =1;i<si;i++)
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j-1>=0 && j<triangle[i-1].size())
                {
                    triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
                }
                else if(j-1<0 && j<triangle[i-1].size())
                {
                    triangle[i][j]+=triangle[i-1][j];
                }
                else if(j-1>=0 && j>=triangle[i-1].size())
                {
                    triangle[i][j]+=triangle[i-1][j-1];
                }

            }

        int ans=INT_MAX;
        for(int i=0;i<triangle[si-1].size();i++)
        {
            if(triangle[si-1][i]<ans)
                ans=triangle[si-1][i];
        }
        return ans;
    }
};
