#include <iostream>


class Solution {
public:
   struct _2d{
            int x,y;
            bool operator ==(const struct _2d  &a) const {
                return x == a.x && y == a.y;
            }
        };
    struct _2d_hash_struct {
        size_t operator()(const struct _2d & p) const {
            return ((size_t) p.x << 32) & p.y;
        }
    };

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort( nums.begin(), nums.end() );

     

        unordered_map<_2d,int,_2d_hash_struct> vst;
        vector<vector<int> > res;
        int sz = nums.size();
        for ( int i = 0; i < sz - 2; ++i) {
            if ( i &&  nums[i] == nums[ i -1])
                continue;
            for ( int j = i + 1; j < sz -1; ++j) {
                if ( j - 1 != i && nums[j - 1] == nums[j])
                    continue;

                int sum = nums[i] + nums[j];
                if ( sum + nums[sz - 1] < 0)
                    continue;
                if ( sum + nums[j + 1] > 0)
                    break;

                int l = j + 1,r = sz - 1;
                int mid;
                while ( l < r) {
                    mid = (l + r) >> 1;
                    if ( sum + nums[mid] > 0)
                        r = mid - 1;
                    else if ( sum + nums[mid] < 0)
                        l = mid + 1;
                    else
                        break;
                }

                if ( l <= r && sum + nums[mid] == 0) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[mid]);
                    res.push_back(tmp);
                }
            }
        }


        return res;
    }
};


// sort + two_pointer + unique anwser
int main( int argc, char *argv[])
{



    return 0;
}
