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
        vector <int> forward,rev;
        mi=prices[0]-min[0];
        ma=max[si]-prices[si];
        for(int i=0;i<=si;i++)
        {
            if(prices[i]-min[i] > mi)
            {
                forward.push_back(prices[i]-min[i]);
                mi=prices[i]-min[i];
            }
            else
                forward.push_back(mi);
        }

        for(int i=si;i>=0;i--)
        {
            if(max[i] -prices[i] > ma)
            {
                rev.push_back(max[i]-prices[i]);
                ma=max[i] -prices[i];
            }
            else
                rev.push_back(ma);
        }

        reverse(rev.begin(),rev.end());
        int ans=0;
        for(int i=0;i<=si;i++)
            if(forward[i]+rev[i]>ans)
                ans=forward[i]+rev[i];
        return ans;
    }
};
