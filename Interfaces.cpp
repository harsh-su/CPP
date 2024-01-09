#include <iostream>

class  IRender {
  public :
    virtual void Draw()=0;
    virtual void update() =0;
};


class Vulkan : public IRender{
  public :
void Draw() override{
  std::cout << "vulkan draw" << std::endl;}
void update() override {
  std::cout << "vulkan update" << std::endl;}
}; 

class opengl : public IRender {
  public :
    void Draw() override {
      std::cout << "opengl draw" << std::endl;
    }
    void update() override {
      std::cout << "opengl update" << std::endl;
    }  
};


int main(){
  IRender* myrenderer = new opengl;
  myrenderer->update();
  myrenderer->Draw();
  return 0;
}
