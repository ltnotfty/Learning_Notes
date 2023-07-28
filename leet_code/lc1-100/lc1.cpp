#include <iostream>







class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        

        vector<int> res;
        int size = nums.size();
        for (int i = 0;i < size; ++i) {
            for ( int j = i + 1; j < size; ++j) {
                if (nums[i] + nums[j] == target) {
                    res={i,j};
                    return res;
                }
            }
        }   

        return res;
    }
};


class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> um;
        int sz = nums.size();

        vector<int> res;
        for ( int i = 0;i < sz; ++i) {
            if ( um.find(nums[i]) != um.end() ){
                res = {um[nums[i]], i};
                return res;
            } 
            else {
                um[target - nums[i]] = i;
            }
        }

        
        return res;
    }
};




// 1. two loop
// 2. hash table




int main() {


    return 0;
}
