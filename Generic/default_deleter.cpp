#include<iostream>
#include <memory>

struct Intdeleter {
    void operator()(int* int_ptr) {
        std::cout << "deleting int" << std::endl;
        delete int_ptr;
    }
};

//why use custom deleter 
 


int main(){
    std::unique_ptr<int, Intdeleter> ptr(new int(10));

    return 0;

}