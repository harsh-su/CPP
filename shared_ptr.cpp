#include<iostream>
#include<memory>

class UDT {
    public :
    UDT(){
        std::cout << "UDT constructed " << " \n";

    }
    ~UDT(){
        std::cout << "UDT destroyed" << "\n";
    }
};


int main(){
    std::shared_ptr<UDT> ptr1 = std::make_shared<UDT>();

    {
        std::shared_ptr<UDT> ptr2 = ptr1 ;
        std::cout << "use count is " << ptr2.use_count() << "\n";
    }

    std::cout << "use count is " << ptr1.use_count() << "\n";

}