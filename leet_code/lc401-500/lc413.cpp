#include <iostream>


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        // C(3) = 1
        // C(4) = (4-3+1)+1
        // C(5) = (5 - 4 + 1)C(4) + 1 
    
        int res = 0;
        int sz = nums.size();
        for ( int i = 0; i < sz - 1; ++i) {
            nums[i] = nums[i + 1] - nums[i];
        }

        int len = 2;
        for ( int i = 1; i < sz - 1; ++i) {
            if (nums[i - 1] == nums[i]) {
                len++;
            }
            else{
                res += (len - 2)* (len -1)/2;
                len = 2;
            }   
        }
        res += (len - 2) * (len - 1) /2 ;

        return res;
    }
};

// Gauss + slide


int main( int argc, char *argv[])
{







    return 0;
}
