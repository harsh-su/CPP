#include <iostream>

struct noncopyable {
  //noncopyable()=default;
  noncopyable(const noncopyable&rhs )=delete;
  noncopyable& operator=(const noncopyable&rhs ) =delete;

};


struct Dog : public noncopyable {
  virtual void bark(){
    std::cout << "Dog:bark" << std::endl;
  }
};

struct Golden :public Dog{
  virtual void bark() override {
    std::cout << " golden :: bark" << std::endl;
  }
};

struct Bordercollie : public Dog {
  virtual void bark() override {
    std::cout << "baorder :: bark" << std::endl;
  }
};

struct Colretreiver : public Golden,Bordercollie {
  void bark() override {
    std::cout << "colretreiver :: bark" << std::endl;
  }
};

int main(){
  Dog* dog = new Dog;
  Dog* golden = new Golden;
  Dog* bordercollie = new Bordercollie;
  Colretreiver * colretreiver =new Colretreiver;

  dog->bark();
  golden->bark();
  bordercollie->bark();
  colretreiver->bark();

  dog = golden;


}
