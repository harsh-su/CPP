#include "student.hpp"

#include<iostream>

student::student(){
    m_name = "no name";
    std::cout << "constuctor : " << "\n";
    std::cout << "m_name is " << m_name << "\n";
}

student::student(std::string name){
    m_name  =name;
    std::cout << "constructor " <<"\n";
    std::cout << "m_name is " << m_name << std::endl;
}

student::~student(){
    std::cout << "destructor" << "\n";
}

void student::printname(){
    std::cout << "form func m_name is" << m_name << "\n"; 
}