#include <string>
#include <iostream>

class toplevel {
public:
  toplevel(std::string arg){std::cout << "top level class" << std::endl;}

};

class Entitybase: public toplevel {
  public :
    Entitybase() : toplevel("arg") {
      std::cout << "Entitybase constuctor" << std::endl;
    }

    Entitybase(std::string name) :toplevel("arg"),m_name(name){
      std::cout << "Entitybase(name)" << std::endl;
    }

    ~Entitybase(){
      std::cout << "Entitybase Destructor" << std::endl;
    }
    std::string m_name;
};

class Monster : public Entitybase{
public:
  Monster() : Entitybase("default"){
              std::cout << "Monster construc" << std::endl;
            };
 ~Monster(){
   std::cout << "monster destructor" << std::endl;
 };

};

int main () {

  Monster badmonster;

  return 0;
}
