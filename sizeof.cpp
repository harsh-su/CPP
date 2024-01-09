#include <iostream>

int main(){

    int x =4;
    int* px = &x;
    int array[] = {1,2,3,4,5};
    int* dynmicallyallocatedarray = new int[1000];

    std::cout << "better to use size() to get num elements then sizeof() " << "\n";

    std::cout << "as x is local variable defined at compile time x is "<< sizeof(x) <<std::endl;
    std::cout << "In a 64 bit machien to store any addres 8 bit is required therefore px is"  << sizeof(px) << std::endl;
    std::cout << "each var is 4 byte therefore array is "<< sizeof(array) << std::endl;
    std::cout << "only a pointer again dynamicallyallotedarray is " << sizeof(dynmicallyallocatedarray) <<std::endl;
}