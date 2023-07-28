#include <iostream>


// sort + math 
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int sz = nums.size(); 
        
        int csum = 0;
        int rnum = 0;
        int lnum = 0;
        for ( int i = 1; i < sz; ++i) {
            if (  nums[i - 1] == nums[i]) {
                rnum = nums[i];
            }
            else{
                csum += nums[i];
            }
        }
        csum += nums[0];
        
        lnum = (sz + 1) * sz / 2 - csum;


        return { rnum, lnum};
    }
};





// hash table 
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int> mp;
        
        int rnum;
        int lnum;
        for ( auto num: nums) {
            mp[num]++;
            if ( mp[num] == 2)
                rnum = num;
        }

        for ( int i = 1;i <= n; ++i) {
            if ( mp.find(i) == mp.end())
                lnum = i;
        }

        return {rnum , lnum };
        
    }
};



// bitset
// we can get xorNum = lost_num ^ repeat_num by xor a array[1, n]
// and we can split two nums by xorNum's lowbit
// and foreach arr in num find lost_num and repeat_num
//

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();
        
        // cal lnum ^ rnum

        int xorNum = 0;
        for ( int i = 1;i <= n; ++i)
            xorNum ^= i;
        for ( auto num: nums) 
            xorNum ^= num;

        // group by lowbit
        
        int lb = xorNum & (-xorNum);
        int nums1 = 0;
        int nums2 = 0;
        
        for ( int i = 1; i <= n; ++i ) {
            if ( (i & lb) == 0) 
                nums1 ^= i;
            else
                nums2 ^= i;
        }
        for ( auto num: nums ) {
            if ( (num & lb) == 0)
                nums1 ^= num;
            else
                nums2 ^= num;
        }

        for ( auto num: nums) {
            if ( num == nums1) {
                return {nums1, nums2};
            }

        }

        return {nums2, nums1};
    }
};




class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();
        vector<int> book(n + 1, 0);

        for ( int num: nums ) {
            book[num]++;
        }

        int lnum = 0;
        int rnum = 0;
        for ( int i = 1;i <= n; ++i) {
            if ( book[i] == 2) {
                rnum = i;
            }
            if ( book[i] == 0)
                lnum = i;
        }

        return { rnum , lnum };
    }
};

// couting sort



int main( int argc, char *argv[] ){






    return 0;
}
