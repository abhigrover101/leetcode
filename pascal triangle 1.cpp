class Solution {
public:
    vector<vector<int> > generate(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<int> even(rowIndex+1,0),odd(rowIndex+1,0),temp;
        vector< vector<int> > ans;
        ans.clear();
        even[0]=1;
        int j,i;
        for(i=0;i<rowIndex;i++)
        {
            if(i%2!=0)
            {
                for(j=0;j<=i;j++)
                {
                    if(j-1>=0 && j<=i-1)
                        odd[j]=even[j-1]+even[j];
                    if(j-1<0 && j<=i-1)
                        odd[j]=even[j];
                    if(j-1>=0 && j>i-1)
                        odd[j]=even[j-1];
                    temp.push_back(odd[j]);
                }
                ans.push_back(temp);
                temp.clear();
            }
            else
            {
                for(j=0;j<=i;j++)
                {
                    if(j-1>=0 && j<=i-1)
                        even[j]=odd[j-1]+odd[j];
                    if(j-1<0 && j<=i-1)
                        even[j]=odd[j];
                    if(j-1>=0 && j>i-1)
                        even[j]=odd[j-1];
                    temp.push_back(even[j]);
                }
                ans.push_back(temp);
                temp.clear();
            }

        }

        return ans;
    }
};
