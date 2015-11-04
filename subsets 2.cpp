class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,k,si=(1<<(S.size()));
        set < vector<int> > sub;
        vector < vector<int> > ans;
        vector<int> temp;

        for(i=0;i<si;i++)
        {
            j=i;
            k=0;
            temp.clear();
            while(j)
            {
                if(j&1)
                    temp.push_back(S[k]);
                k++;
                j=j>>1;
            }
            sort(temp.begin(),temp.end());
            if(sub.count(temp)==0)
            {
                sub.insert(temp);
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;

    }
};
