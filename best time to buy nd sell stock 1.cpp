class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0)
            return 0;
        int mi,ma;

        mi=prices[0];
        ma=prices[prices.size()-1];

        vector <int> min,max;
        int si=prices.size()-1;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<mi)
            {
                mi=prices[i];
                min.push_back(mi);
            }
            else
                min.push_back(mi);
            if(prices[si-i]>ma)
            {
                ma=prices[si-i];
                max.push_back(ma);
            }
            else
                max.push_back(ma);
        }

        reverse(max.begin(),max.end());
        int ans=0;
        for(int i=0;i<=si;i++)
        {
            if(max[i]-min[i]>=ans)
                ans=max[i]-min[i];
        }
        return ans;
    }
};
