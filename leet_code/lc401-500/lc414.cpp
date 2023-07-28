#include <iostream>




class Solution0 {
public:
    int thirdMax(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int sz = nums.size();


        int tm = 0;
        int p = sz - 1;

        while ( tm  < 2 ) {

            while ( p > 0 && nums[p] == nums[p - 1])
                --p;

            if ( p == 0)
                break;
            
            ++tm;
            if ( tm != 2) {
                --p;
            }
        }

        if ( tm != 2)
            return nums[sz - 1];
        else {
            return nums[p - 1];
        }

    }
};


class Solution {
public:
    void insert_val(int *arr, int &p, int val) {

        if ( arr == NULL)
            return;
        
        int ins_pos = 0;
        for ( int i = p - 1; i > -1; --i ) {
            if ( val == arr[i])
                return ;
            
            if ( val < arr[i]) {
                ins_pos = i + 1;
                break;
            }
        }



        for ( int j = p - 1; j >= ins_pos; --j) {
            if ( j + 1 < 3){
                arr[j + 1] = arr[j]; 
            }
        }

        if ( ins_pos < 3) {
            arr[ins_pos] = val;
            if (p < 3)
                ++p;
        }

    }

    int thirdMax(vector<int>& nums) {
        
        int sz = nums.size();
        


        int m[3];
        int mp = 0;

        for ( int i = 0; i < sz; ++i) {
            insert_val(m, mp, nums[i]);
        }

        if ( mp == 3)
            return m[2];
        else
            return m[0];

    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {

       long  a = LONG_MIN;
       long  b = LONG_MIN;
       long  c = LONG_MIN;


       for ( long num: nums) {
           if ( num > a) {
               c = b;
               b = a;
               a = num;
           }
           else if ( num < a && num > b) {
               c = b;
               b = num;
           }
           else if ( num < b &&　num > c) {
               c = num;
           }
       }

     
        return c == LONG_MIN ? a : c;
    }
};


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;

        for (auto num: nums) {
            s.insert(num);
            if (s.size() > 3) {
                s.erase(s.begin() );
            }
        }

        return s.size() == 3 ? *s.begin() : *s.rbegin();
     }
};

// in order set
// insert sort



int main( int argc, char *argv[])
{




    return 0;
}
