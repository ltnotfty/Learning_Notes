#include <iostream>






class Solution {
public:
    int rob(vector<int>& nums) {

        int hm_nb =  nums.size();
        int dp[100] = {0};
        for ( int i = 0; i < hm_nb; ++i) {
            
            if ( i == 0 )
                dp[i] = nums[i];
            else if ( i == 1)
                dp[i] = max(dp[i - 1], nums[i]);
            else
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);

        }

        return dp[hm_nb - 1];
    }
};

// dp
int main( int argc, char *argv[])
{





    return 0;
}
