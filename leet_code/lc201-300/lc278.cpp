#include <iostream>


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
 
int firstBadVersion(int n) {
    int l = 1;
    int r = n ;

    while(l < r){
        int mid = (r - l >> 1) +　l  ;
        
        if(isBadVersion(mid)) r = mid;
        else l = mid + 1;
    }

    return l;
    }
};


// binary search



int main( int argc, char *argv[]) {


    

    return 0;
}
