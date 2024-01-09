#include<iostream>
template <typename T,int size>
class Container{
    public :
        Container(){
            m_data = new T[size];
        }
        ~Container(){
            delete[] m_data;
        }

        static T m_variable ;

     
    private :
        T* m_data;
};

//telling compiler to initialize the static variable
template <typename T,int size>
T Container<T,size>::m_variable =0;

int main(){ 
    Container <int,2> c;
    Container<int,5>::m_variable =7;
    Container<int,7>::m_variable =112;

    std::cout << Container<int,5>::m_variable << std::endl;
    std::cout << Container<int,7>::m_variable << std::endl;

}