#include <iostream>


class Solution {
public:
    int search(vector<int>& nums, int target) {
        

        int sz = nums.size();
        
        
        int l = 0;
        int r = sz - 1;
        int all_inc = 0;
        if ( nums[0] < nums[sz - 1])
            all_inc = 1;

        while ( l <= r ) {
            int mid = (l + r) >> 1;

            if ( nums[mid] == target)
                return mid;
            
            if ( nums[l] <= nums[mid] && target >= nums[l] && target < nums[mid])
                r = mid  - 1;
            else if ( nums[mid] < nums[r] && ( target > nums[r] || target < nums[mid]))
                r = mid - 1;
            else 
                l = mid + 1;
        }

        

        return  -1;
    }
};


class Solution2 {
public:
    int search(vector<int>& nums, int target) {


        int sz = nums.size();


        int l = 0;
        int r = sz - 1;
        int all_inc = 0;
        if ( nums[0] < nums[sz - 1])
            all_inc = 1;

        while ( l <= r ) {
            int mid = (l + r) >> 1;

            if (nums[mid] == target) return mid;
            if ( nums[l] <= nums[mid] ) {
                if ( nums[l] <= target && nums[mid] > target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else {
                if ( target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }

        }


        return  -1;
    }
};


// binary search 

int main( int argc, char *argv[]) {

    




    return 0;
}
