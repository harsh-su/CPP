#include<iostream>

template <typename first, typename second>
struct Entity{
Entity(first key,second value ){

    m_key = key;
    m_value = value;
}
    first m_key;
    second m_value;
};


int main(){
    Entity e(5,100.1f);

    //here i dont need to explicitly mention the type
    std::cout << e.m_value << std::endl;
    std::cout << e.m_key << std::endl;
}

