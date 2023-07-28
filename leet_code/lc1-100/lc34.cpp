#include <iostream>
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {    

        int sz = nums.size();
        int l = 0;
        int r = sz - 1;

        
        vector<int> res = { -1,-1};
        int mid;


        while (r - l > 0) {
            int mid = l + (r - l >> 1);
            if ( nums[mid] == target)
                r = mid;
            else if( nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        if ( sz == 0 || nums[l] != target)
            return res;

        res[0] = l;

        int rl = l;
        int rr = sz - 1;

        while ( rr - rl > 1) {
            int rmid = (rr + rl) >> 1;

            if ( nums[rmid] == target)
                rl = rmid;
            else
                rr = rmid;
        }

        if ( nums[rr] == target)
            res[1] = rr;
        else
            res[1] = rl;



        return res;
    }
};


class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {    

        int sz = nums.size();
        int l = 0;
        int r = sz - 1;

        
        vector<int> res = { -1,-1};
        int mid;
        while ( l<= r) {

            mid = (l + r) >> 1;

            if ( target > nums[mid])
                l = mid + 1;
            else if ( target < nums[mid])
                r = mid - 1;
            else
                break;

        }
        if ( l > r)
            return res;

        int ll = 0;
        int lr = mid;

        while ( lr - ll > 1) {
            int lmid = (lr + ll) >> 1;

            // printf("lmid: %d %d\n", lmid, nums[lmid]);
            if ( nums[lmid] == target)
                lr = lmid;
            else
                ll = lmid;
        }

        if ( nums[ll] == target)
            res[0] = ll;
        else   
            res[0] = lr;

        int rl = mid;
        int rr = sz - 1;

        while ( rr - rl > 1){
            int rmid = (rl + rr) >> 1;

            if ( nums[rmid] == target)
                rl = rmid;
            else
                rr = rmid;
        }

        if (nums[rr] == target)
            res[1] = rr;
        else
            res[1] = rl;


        return res;
    }
};
// binary search 


int main( int argc, char *argv[])
{






    return 0;
}
