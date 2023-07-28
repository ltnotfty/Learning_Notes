#include <iostream>



// hash table 

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {


        vector<int> v_arr(50000, 0);

        int dg = 0;
        for ( int num: nums) {
            v_arr[num]++;
            dg = max(v_arr[num], dg);
        }

        set<int> mx_v;
        for ( int i = 0; i < 50000; ++i ) {
            if ( v_arr[i] == dg ) {
                mx_v.insert(i);
            }
        }

        unordered_map<int, pair<int, int> > um_sa;
        int sz = nums.size();
        for ( int i = 0; i < sz; ++i ) {
            if ( mx_v.find(nums[i]) != mx_v.end()) {
                auto item = um_sa.find( nums[i] );
                if ( item == um_sa.end())
                    um_sa[nums[i]] = make_pair(i, i);
                else {
                    item->second.second = i;
                }
            }
        }

        int len = 100000;
        for ( auto &[k,v]: um_sa) {
            len = min(len, v.second - v.first + 1);
        }

        return len;
    }
};



class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        
        vector<int> v_arr(50000, 0);

        int dg = 1;
        int n = nums.size();
        int res = n;
        for ( auto num: nums )
            v_arr[ num ]++, dg = max(dg, v_arr[num]);
        std::fill(v_arr.begin(), v_arr.end(), 0);

        
        int l = 0;
        int r = 0;

        while ( r < n ) {
            v_arr[ nums[r] ]++;
            int v = v_arr[nums[r]];
            

            while ( v == dg && nums[r] != nums[l] )
                v_arr[nums[l]]--,++l;

            if ( v == dg ) {
                res = min(res, r - l + 1);
            }
           // std::cout << r << std::endl;
            ++r;
        }

        return res;
    }
};


// sliding windows + hash table

int main( int argc, char *argv[] ) {














    return 0;
}
