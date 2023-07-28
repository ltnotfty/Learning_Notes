#include <iostream>


class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int sz = nums.size();
        if ( sz < 3)
            return 0;

        sort( nums.begin(), nums.end() );

        int non_pos = 0;
        while ( non_pos <  sz && nums[ non_pos] < 0) {
            non_pos++;
        }


        int v1 = nums[sz - 1] * nums[sz - 2] * nums[sz - 3];
        if ( non_pos < 2 || non_pos == sz) {
            return nums[sz - 1] * nums[sz - 2] * nums[sz - 3];
        }

        int v2 = nums[0] * nums[1] * nums[sz - 1];

        return max(v1, v2);

    }
};

// sort



int main( int argc, char *argv[])
{






    return 0;
}
