#include<iostream>

template<typename T1,typename T2>
auto Multiply(const T1& a,const T2& b)-> decltype(a*b){
    return a*b;
}

int main(){

    std::cout << Multiply<float,int>(7.22f,5) << std::endl;
} 