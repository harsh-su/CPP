#include <iostream>
#include <string>

struct Entity{
    std::string name ;
    int x;
    int y;
    int *collections;
};

int main(){

    Entity e{};
    std::cout << e.name << std::endl;
    std::cout << e.x <<std::endl;

}