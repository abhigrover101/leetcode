class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size()==0)
            return 0;
        int ans=0;
        int bought=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<bought)
                bought=prices[i];
            else if(prices[i]>bought)
            {
                ans+=(prices[i]-bought);
                bought=prices[i];
            }

        }
        return ans;

    }
};
