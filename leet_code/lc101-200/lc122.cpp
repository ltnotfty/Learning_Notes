#include <iostream>

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int sz = prices.size();
        vector<vector<int> > dp;

        for (int i = 0;i < sz + 1; ++i) {
            vector tmp(sz + 1, 0);
            dp.push_back(tmp);
        }   

        for ( int i = 1; i < sz + 1; ++i) {

            for ( int j = 1; j < sz + 1; ++j) {
                
                dp[i][j] = dp[i][j - 1];
                for (int k = 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k - 1] + prices[j - 1] - prices[k - 1]);
                }
            }
        }
        int res = dp[sz][0];
        for (int i = 1; i < sz + 1; ++i)
            res = max(res, dp[sz][i]);

        return res;
    }
};


class Solution1 {
public:
    int maxProfit(vector<int>& prices) {

        int sz = prices.size();

        int res = 0;
        for (int i = 0;i < sz -1; ++i) {
            if (prices[i] < prices[i + 1])
                res += prices[i + 1] - prices[i];
        }

        return res;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {

        int sz = prices.size();
        
        int hv_tk = -prices[0];
        int no_tk = 0;


        for ( int i = 1;i < sz; ++i) {
            int tmp_hv_tk = hv_tk;
            hv_tk = max(hv_tk, no_tk - prices[i]);
            no_tk = max(no_tk, tmp_hv_tk + prices[i] );
        }



        return no_tk;
    }
};
// dp or greedy
int main( int argc, char *argv[])
{


    std::cout << sizeof(arr)/sizeof(arr[0]) << std::endl;




    return 0;
}
