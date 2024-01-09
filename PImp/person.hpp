#ifndef PERSON_HPP
#define PERSON_HPP

#include <memory>
#include <string>

class Person{
    public :
        Person(std :: string s);
        ~Person();
        std::string Getattributes();

    private:
        struct pimlperson;
        std::unique_ptr<pimlperson>m_impl;
};


#endif