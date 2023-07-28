#include <iostream>





class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // negative ignore
        // 1 ~k    k + 1
        // !1 ....  1
        // 1~k  k + 2 ....

        int sz = nums.size();

        for ( int i = 0; i < sz; ++i ) {
            int curpos = i;
            int prev = -1;

            while (1) {

                if ( curpos < 0 || curpos > sz - 1 ) {
                    break;
                }
                else if ( nums[curpos] == curpos + 1) {
                    break;
                }
                else {
                    int nxtpos = nums[curpos];
                    if (nxtpos < 1 || nxtpos > sz)
                        nxtpos = -1;

                    nums[curpos] = prev;
                    prev = nxtpos ;
                    curpos = nxtpos - 1;
                }
            }
        }


        for (int i = 0; i < sz; ++i ) {
            if ( i + 1 != nums[i] )
                return i + 1;
        }

        return sz + 1;
    }
};
// hash 



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // negative ignore
        // 1 ~k    k + 1
        // !1 ....  1
        // 1~k  k + 2 ....

        int sz = nums.size();   

        for ( int &num: nums) {
            if (num <= 0 || num > sz)
                num = sz + 1;
        }
        
        for ( int i = 0; i < sz; ++i ) {
            int abv = abs(nums[i]);
            if ( abv > 0 && abv < sz + 1 ) {
                nums[abv - 1] = -abs(nums[abv - 1]);
            }
        }


        for ( int i = 0; i < sz; ++i) {
            if ( nums[i] >= 0)
                return i + 1;
        }


        return sz + 1;
    }
};

// negative flag 



int main( int argc, char *argv[])
{









    return 0;
}
