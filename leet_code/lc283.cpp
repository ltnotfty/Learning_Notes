#include <iostream>






// count zero num

void moveZeroes(int* nums, int numsSize){
    
    int i;
    int cnt = 0;
    for( i = 0;i < numsSize;i++)
        if(!nums[i]) cnt++;

    int p = 0;
    for( i = 0;i < numsSize;i++)
        if(nums[i]) nums[p++] = nums[i];

    i = 0;
    while(i < cnt){
        nums[numsSize - 1 - i] = 0;
        i++;
    }

}


// two pointer 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int r = 0;
        int l = 0;

        int rb = nums.size();

        while ( r < rb) {

            while ( r < rb && nums[r] == 0)
                r++;
            while ( l < r && nums[l] != 0)
                l++;

            if ( l != r && r < rb) {
                nums[l] = nums[r];
                nums[r] = 0;
            }
            ++r,++l;
        }

        return ;
    }
};



// quick sort
class Solution {
public:
    void moveZeroes(vector<int>& nums) {


        int j = 0;
        int sz = nums.size();
        for ( int i = 0; i < sz; ++i ) {
            if ( nums[i] ){
                if ( i > j) {
                nums[j] = nums[i];
                nums[i] = 0;
                }
                ++j;
            }
        }

        return ;
    }
};


// formal solution 


class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        
        int n = nums.size();
        int l = 0;
        int r = 0;

        while ( r < n) {
            if ( nums[r] ) {
                if ( r > l) {
                    nums[l] = nums[r];
                    nums[r] = 0;
                }
                ++l;
            }
            ++r;
        }

        return ;
    }
};



int main( int argc, char *argv[])
{





    return 0;
}
