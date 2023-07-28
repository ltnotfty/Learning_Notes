#include <iostream>





// two pointer and sliding windows

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0,r = 0;
        int rb = s.size();

        int res = 0;
        vector<int> hs( 256, 0);
        while ( r < rb ) {
            hs[s[r++]]++;

            while ( l < r && hs[s[r - 1]] == 2) {
                hs[s[l]]--;
                l++;
            }
            res = max(res, r - l);
        }


        return res; 
    }
};

















int main( int argc, char *argv[])
{



    return 0;
}
