class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(),num.end());
        int i,start,end,dif=INT_MAX,ans;
        for(i=0;i<num.size();i++)
        {
            start=i+1;
            end=num.size()-1;
            while(start<end)
            {
                if(abs(num[i]+num[start]+num[end]-target) < dif)
                {
                    dif=abs(num[i]+num[start]+num[end]-target);
                    ans=num[i]+num[start]+num[end];
                }
                if(num[i]+num[start]+num[end]-target > 0)
                    end--;
                else if(num[i]+num[start]+num[end]-target < 0)
                    start++;
                else
                    return ans;
            }
        }
        return ans;
    }
};
