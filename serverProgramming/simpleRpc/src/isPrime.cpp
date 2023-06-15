//
// Created by xOx on 2023/6/13.
//

#include "isPrime.h"



bool isPrime( int num )
{
    if ( 0 >= num )
        return false;
    if (1 == num)
        return true;

    if (num < 4)
        return true;

    for ( int i = 2; i <= num/i; ++i)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int add(int a, int b)
{
    return a + b;
}


void printTest()
{
    printf("Have Recv It!!!\n");
}

float  noisyFun(float  a, int tm)
{

    float base = 1.0;
    float res  = 0;
    for ( int i = 0; i < tm; ++i ) {
        res += base * a;
        base /= 2;
    }

    return res;
}


