#include<iostream>
#include<string>

int main(){
    std::string str = "lon long string";
    std::string str2 ;

    std::cout << "str value is " << str << std::endl;
    std::cout << "str2 avleue is " << str2 << "\n";

    //now using the move
    //using copy assingnent op
    str2= str ;
    //using move 
    str2 = std::move(str);
    //using typecast
    // str2 = static_cast<std::string&&>(str);

    std::cout << "str value is " << str << std::endl;
    std::cout << "str2 avleue is " << str2 << "\n";

}