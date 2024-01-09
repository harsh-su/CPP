#include<iostream>
template <typename T=int,int size=10>
class Container{
    public :
        Container(){
            m_data = new T[size];
            std::cout<<size<<std::endl;
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
    Container c2;
    

}