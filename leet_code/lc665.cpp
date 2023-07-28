#include <iostream>




// stack
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        stack<int> ps;

        int flag = 0;
        for (int num:nums) {

            
            if ( ps.empty() || ps.top() <= num) {
                ps.push(num);
                continue;
            }

            int topVal = ps.top();
            if (flag)
                return false;
            else {
                
                ps.pop();
                if ( ps.empty() || ps.top() <= num ) {
                    ps.push(num);
                    ps.push(num);
                }
                else {
                    ps.push(topVal);
                    ps.push(topVal);
                }
                flag = 1;
            }
        }

        return true;
    }
};

// scan in two positon 

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {


        int sz = nums.size();

        int i;
        for ( i = 0; i < sz - 1; ++i){
            if ( nums[i] > nums[i + 1])
                break;
        }

        if ( i == sz - 1)
            return true;

        int j = sz - 1;

        for ( ; j > 0; --j) {
            if ( nums[j - 1] > nums[j])
                break;
        }


        if ( i + 1 == j && ( i == 0 || j == sz - 1 || nums[i] <= nums[j + 1] || nums[j] >= nums[i - 1]))
            return true;

        return false;
    }


};





class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        

        int sz = nums.size();

        int cnt = 0;
        for ( int i = 0; i < sz  - 1; ++i) {
            if ( nums[i] > nums[i + 1]) {
                cnt++;
                if ( i > 0 && nums[i + 1] > nums[i - 1])
                    nums[i + 1] = nums[i];
            }
        }

        return cnt < 2;
    }


    // 0 1
    // 
};

// com nums[ i ] and nums[ i + 1]
// if have i - 1 compare with nums[i + 1]




int main(int argc, char *argv[]) {







    return 0;
}
