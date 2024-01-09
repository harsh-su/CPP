#include <iostream>

union U {
    int i;
    short s;
    float f;

}

int main(){
    U u;
    u.i =10;
    std::cout << u.i << std::endl;
    std::cout << u.s <<std::endl;
    std::cout << sizeof(u) << std::endl;
    
}