#include <iostream>





class Solution {
public:
    int minMoves(vector<int>& nums) {

        sort( nums.begin(), nums.end());

        int sz = nums.size();
        int r = sz - 1;
        int l = sz - 1;

        int res = 0;
        while ( l > -1) {

            while ( l > -1 && nums[r] == nums[l])
                --l;
            if ( l > -1)
                res += (sz - l - 1) * ( nums[r] - nums[l]);
            r = l;
        }

        return res;
    }
};
// sort + two pointer

class Solution {
public:
    int minMoves(vector<int>& nums) {


        int minNum = *min_element( nums.begin(), nums.end() );

        int res = 0;

        for ( int num: nums)
            res += num - minNum;

        return res;
    }
};



// math + minval





int main( int argc, char *argv[])
{




    return 0;
}
