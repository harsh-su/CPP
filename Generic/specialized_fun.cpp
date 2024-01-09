#include<iostream>
#include<cmath>

template<typename T>
bool equal(T a, T b){
    return (a==b);
}

//specialzed function for float 

template<>
bool equal<float>(float a, float b){
    std::cout<< "specialized function for float" << std::endl;
    return fabs(a-b) < 0.00001f;
}

//similar for double
template<>
bool equal<double>(double a, double b){
    std::cout<< "specialized function for double" << std::endl;
    return fabs(a-b) < 0.0000001;
}

int main(){

    std::cout << equal(1,1) << std::endl;
    std::cout << equal(1,2) << std::endl;

    std::cout << equal<float>(1.0f-0.999999f,0.000001f) << std::endl; 
    std::cout <<  equal<float>(1.0f,0.9999f) << std::endl;

    std::cout << equal<double>(1.0-0.999999999,0.00000001) << std::endl;

}