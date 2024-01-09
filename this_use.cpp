#include <iostream>

class Person{
    public : 
    Person(int age) : age(age){

    }

    int getage() const {
        return age;
    }

    Person*Getthisaddress(){
        return this;
    }

    private :
        int age;
};

int main(){
    Person mike(500);

    std::cout <<mike.Getthisaddress()<<std::endl;
    std::cout << &mike <<std::endl;

    Person * harshal = new Person(700);
    std::cout <<harshal->Getthisaddress() <<std::endl;
    std::cout << &harshal <<std::endl;
    std::cout << harshal <<std::endl;
    delete harshal;
}