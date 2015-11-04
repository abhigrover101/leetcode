class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector <pair <string,int> > input;
        vector<string> sorted,ans;
        int flag=0;
        sorted=strs;
        for(int i=0;i<strs.size();i++)
        {
            sort(sorted[i].begin(),sorted[i].end());
            input.push_back(make_pair(sorted[i],i));
        }
        sort(input.begin(),input.end());
        for(int i=0;i<input.size()-1;i++)
        {
            if(input[i].first==input[i+1].first)
            {
                ans.push_back(strs[input[i].second]);
                if(i==input.size()-2)
                    ans.push_back(strs[input[i+1].second]);
                flag=1;
            }
            else if(flag==1)
            {
                flag=0;
                ans.push_back(strs[input[i].second]);
            }
        }
        return ans;
    }
};
