#include <iostream>

class baseclass {
public:
  baseclass(){
    std::cout << "Base const" << std::endl;
    basedata =new int[10];
  };
  baseclass(baseclass &&) = default;
  baseclass(const baseclass &) = default;
  baseclass &operator=(baseclass &&) = default;
  baseclass &operator=(const baseclass &) = default;
  virtual ~baseclass(){ std::cout << "base dest" << std::endl;
    delete[] basedata;
};
  virtual void Memberfunc(){
    std::cout << "base : mem" << std::endl;
  }

  int*basedata;
};

class derivedclass : public baseclass {
public:
  derivedclass(){
    std::cout << "dervied const" << std::endl;
    deriveddata =new int[15];
  }
  ~derivedclass(){
    std::cout << "dervied dest" << std::endl;
    delete[] deriveddata;
  }


  void Memberfunc() override {
    std::cout << "dervied : mem" << std::endl;
  }

  int*deriveddata;
  
};

int main(){
  baseclass* instance = new derivedclass ;
  instance->Memberfunc();
  delete instance;

} 
