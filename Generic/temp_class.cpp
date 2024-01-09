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
     
    private :
        T* m_data;
};

int main(){ 
    Container <int,2> c;
    Container<float,7> c2;
    
}