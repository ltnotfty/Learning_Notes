#include <iostream>





class Solution {
public:
    int maxProfit(vector<int>& prices) {

        vector<int> l2r(prices.size(), 0);
        vector<int> r2l(prices.size(), 0);

        int sz = prices.size();

        int left_min = prices[0];
        for ( int i = 1; i < sz; ++i) {
            l2r[i] = max(l2r[i - 1], prices[i] - left_min);
            if (left_min > prices[i])
                left_min = prices[i];
        }

        int right_max = prices[sz - 1];

        for ( int i = sz - 2; i > -1; --i) {
            r2l[i] = max(r2l[i + 1], right_max - prices[i]);
            if ( right_max < prices[i])
                right_max = prices[i];
        }

        int res = max(l2r[sz - 1], r2l[0]);
        for (int i = 0;i < sz - 1; ++i) {
            res = max(res, l2r[i] + r2l[i + 1]);
        }

        return res;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {


        int buy1 = -prices[0];
        int buy2 = -prices[0];
        int sell1 = 0 ;
        int sell2 = 0;
        int sz = prices.size();


        for ( int i = 1; i < sz; ++i) {
            sell1 = max(sell1, buy1 + prices[i]);
            buy1 = max(buy1, -prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
            buy2  = max(buy2, sell1 - prices[i]);
        }



        return sell2;
    }
};



// slide from two sides
// or dp


int main( int argc, char *argv[])
{











    return 0;
}
