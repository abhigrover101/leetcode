class Solution {
public:

    int largestRectangleArea(vector<char> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        stack <int> st;
        int li[100000]={0},ri[100000]={0};
        //st.push(0);
        int i=0,max=0;
        for(i=0;i<height.size();i++)
        {
            while(!st.empty() && height[i]<=height[st.top()])
            {
                st.pop();
            }
            if(st.empty()==true)
                li[i]=i;
            else
            {
                li[i]=i-st.top()-1;
            }
            st.push(i);
        }
        while(!st.empty())
            st.pop();

        for(i=height.size()-1;i>=0;i--)
        {
            while(!st.empty() && height[i]<=height[st.top()])
            {
                st.pop();
            }
            if(st.empty()==true)
                ri[i]=height.size()-i-1;
            else
            {
                ri[i]=st.top()-i-1;
            }
            st.push(i);
        }

        for(i=0;i<height.size();i++)
        {
            if(max<(li[i]+ri[i]+1)*height[i])
                max=(li[i]+ri[i]+1)*height[i];
        }
        return max;

    }

    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector <vector <char> > ans=matrix;
        int i=0,max=0,a=0,j=0;
        for(i=0;i<matrix.size();i++)
        {
            for(j=0;j<matrix[i].size();j++)
            {
                if(i==0)
                    ans[i][j]=ans[i][j]-'0';
                else if(matrix[i][j]=='1')
                    ans[i][j]=ans[i-1][j]+1;
                else if(matrix[i][j]=='0')
                    ans[i][j]=0;
            }
        }

        for(i=0;i<ans.size();i++)
        {
            a=largestRectangleArea(ans[i]);
            if(max<a)
                max=a;
        }
        return max;


    }
};
