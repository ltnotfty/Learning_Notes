#include <iostream>







class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int sz = nums.size();        
        for ( int i = 0; i < sz; ++i ) {
            int idx = (nums[i] - 1) % sz;
            nums[ idx ] += sz;
        }

        vector<int> ret;
        for ( int i = 0; i < sz; ++i) {
            if ( nums[i]  <= sz )
                ret.push_back(i + 1);
        }


        return ret;
        // 1 1 2
    }
};



// trick nums[i] += sz





class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int prev = -1;

        int sz = nums.size();

        for ( int i = 0; i < sz; ++i) {

            int prev_val = -1;
            int curpos = i;
            while (1) {
                // printf("%d->", curpos);
                if ( curpos < 0 || curpos > sz) {
                 //   printf("\n");
                    break;
                }
                else if( nums[curpos] == curpos + 1) {
                 //    printf("\n");
                    break;
                }
                else {
                    int nxt_pos = nums[curpos] - 1;
                    // printf("nxt pos: %d", nums[curpos]);
                    nums[curpos] = prev_val;
                    prev_val = nxt_pos + 1;
                    curpos = nxt_pos;
                }
            }

        
        }

        vector<int> ret;

        for ( int i = 0; i < sz; ++i) {
            if ( nums[i] != i + 1)
                ret.push_back(i + 1);
        }

        return ret;
        // 1 1 2
    }
};

// simulation 









int main( int argc, char *argv[])
{



    return 0;
}
