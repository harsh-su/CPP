#include <iostream>
#include <initializer_list>

struct UDT {
  UDT(std::initializer_list<int> data): m_data(data){
    std::cout << "initializer_list constructor" << std::endl;
  }

  ~UDT(){

  }

  void Printdata(){
    for (auto & e : m_data){
      std::cout << e << std::endl;
    }
    std::cout << std::endl;
  }
  
  private: 
  std::initializer_list<int> m_data;

};

int main(){
  UDT u{1,2,3};
  u.Printdata();

  return 0;

}
