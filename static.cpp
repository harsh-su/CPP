#include <iostream>

void foo (){
    static int var =0;
    var+=1;
    std::cout << var <<std::endl;
}

int main(){
    for (int i=0;i<10;i++){
        foo();
    }

}