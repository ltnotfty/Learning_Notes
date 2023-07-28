#include <iostream>


class Point3D {

public:

    virtual ~Point3D()
    {}

    float a,b,c;

    static float NUM;
};



int main( int argc, char *argv[])
{

    Point3D p3d;


    float Point3D::*p1 = &Point3D::a;
    float Point3D::*p2 = NULL;

    if ( p1 == p2) {
        printf("p1 & p2 have the same value\n");
    }  
    else{
       printf("a's address: %p\n", &Point3D::a);
       printf("b's address: %p\n", &Point3D::b);
       printf("c's address: %p\n", &Point3D::c);
    }


    return 0;
}
