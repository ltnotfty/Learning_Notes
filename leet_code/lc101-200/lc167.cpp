#include <iostream>


class Solution1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int l = 0;
        int r = numbers.size() -1;


        while ( l < r) {
            if ( numbers[l] + numbers[r] > target) {
                r--;
            }
            else if (numbers[l] + numbers[r] < target) {
                l++;
            }
            else {
                return { l + 1, r + 1};
                break;
            }
        }


        return {};
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> res;
        int sz = numbers.size();
        for ( int i = 0; i < sz - 1; ++i) {
            int l = i + 1;
            int r = sz - 1;
            if ( numbers[i] + numbers[r] < target)
                continue;

            int fVal = target - numbers[i];
            while ( l <= r) {
                int mid = (l + r) >> 1;
                if ( fVal > numbers[mid])
                    l = mid + 1;
                else if ( fVal < numbers[mid])
                    r = mid - 1;
                else {
                    res = { i + 1, mid + 1};
                    break;
                }
            }

            if ( res.size())
                break;
        }

        return res;
    }
};

// binary search + two ptr

int main() {




    return 0;
}
