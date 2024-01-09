#ifndef STUDENT_HPP
#define STUDENT_HPP

#include<string>

class student {
    public:
        student();
        student(std::string name);
        ~student();

        void printname();

    private:
        std::string m_name;
};


#endif 
