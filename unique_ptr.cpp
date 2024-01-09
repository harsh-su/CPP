#include<iostream>
#include<memory>

class UDT {
    public : 
    UDT() {
        std::cout << "UDT created" << "\n";

    }

    ~UDT(){ 
        std::cout << " UDT destroyed " << " \n";
    }
};


int main(){
    std::unique_ptr<UDT> mike = std::unique_ptr <UDT> (new UDT);
    //creating array 
    std::unique_ptr<UDT[]> mike_Array = std::unique_ptr<UDT[]>(new UDT[3]);

    //using make_unique
    std::unique_ptr<UDT[]> harsh_array = std::make_unique<UDT[]>(3);

}