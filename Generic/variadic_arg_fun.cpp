#include<iostream>
#include "cmath"



//base case 
template<typename T>
T Sum( T arg){
    return arg ;
}

//recursive case for number of arguments
template<typename T, typename... Args>
T Sum( T arg, Args... args){
    return arg + Sum(args...);
}

int main(){

    std::cout << Sum<double>(1,2.2,3.3f,4,5) << std::endl;
       

}