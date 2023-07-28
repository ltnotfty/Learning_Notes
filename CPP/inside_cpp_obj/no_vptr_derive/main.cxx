#include <iostream>



class c1{

	public:
int val;
char bit_1;

};


class c2:public c1 {
	public:
		char bit_2;

};


class c3:public c2 {
    public:
	    char bit_3;
 
};


int main( int argc, char *argv[])
{

    c1 c1_obj;
    c1_obj.val = 10;
    c1_obj.bit_1 = 1;


    c2 c2_obj;
    c2_obj.bit_2 = 10;

    c3 c3_obj;
    c3_obj.bit_3 = 20;


    c1 *pc1 = &c1_obj;
    c2 *pc2 = &c2_obj;
    c3 *pc3 = &c3_obj;

    pc1 = pc2;

    *pc2 = *pc1;
    *pc3 = *pc1;

    std::cout << "size of c1 is " << sizeof(c1_obj) << std::endl;
    std::cout << "size of c2 is " << sizeof(c2_obj) << std::endl;
    std::cout << "size of c3 is " << sizeof(c3_obj) << std::endl;


    std::cout << "c2.bit's val is " << c2_obj.bit_2 << std::endl;
    std::cout << "c3.bit's val is " << c3_obj.bit_3 << std::endl;

    return 0;
}
