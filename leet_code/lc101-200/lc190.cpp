#include <iostream>




class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t res = 0;
        uint32_t aval = 1;
        for (int i = 0;i < 32; ++i) {
            if (n & aval) {
                res += (1 << (32 - 1 - i) );
            }
            aval <<= 1;
        }

        return res;
    }
};
// bit operation

int main( int argc, char *argv[])
{



    return 0;
}
