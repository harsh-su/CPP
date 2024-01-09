#include <iostream>
#include <string>

struct Entity
{
    Entity() : name{},x{0},y{0},collection{nullptr}{
        name = std::to_string(x)+ std::to_string(y);
    }

    Entity(std::string _name) : Entity(){
        name = _name;
    }

    Entity(int _x,int _y) :Entity() {
        x =_x;
        y=_y;

    }
    



    std::string name;
    int x{0};
    int y{0};
    int*collection{nullptr};
    
};


int main(){
    Entity e{9,27};
    std::cout << e.name << std::endl;
    std::cout << e.x <<std::endl;
    std::cout <<e.y << std::endl;

}

