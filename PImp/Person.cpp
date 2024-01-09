#include "person.hpp"

struct Person::pimlperson{
    std::string m_name;
    std::string m_strength;
    std::string m_speed;

};

Person::Person(std::string s){
    m_impl = std::make_unique<pimlperson>();

    m_impl->m_name = s ;
    m_impl->m_strength= "n/a";
    m_impl->m_speed= "n/a";
};

Person::~Person(){
}

std::string Person::Getattributes(){
    return m_impl->m_name + "," + m_impl->m_speed + "," + m_impl->m_strength;
}