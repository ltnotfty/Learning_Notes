#include <iostream>


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int res = 0;
        int sz = nums.size();
        
        int clen = 0;
        for ( int i = 0; i < sz; ++i) {
            if ( nums[i] == 1) {
                clen++;
            }
            else{
                res = max(res, clen);
                clen = 0;
            }
        }

        return max(clen, res);
    }
};

// arr

int main( int argc, char *argv[])
{



    return 0;
}
