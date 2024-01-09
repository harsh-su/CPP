#include<iostream>

class Array{
    public:
    Array(){
        std::cout << "constructor" << std::endl;
        data = new int[10];
        for (int i=0;i<10;i++){
            data[i] = i*i;
        }
    }
    ~Array(){
        delete[] data;
    }
    //copy constructor 
    Array(const Array& rhs){
        std::cout << " copy constructor" << "\n";
        data = new int[10];
        for (int i=0;i<10;i++){
            data[i] = rhs.data[i];
        }
    }
    //copy assingmnet operator
    //object is already constructed , we are just making copy later

    Array& operator=(const Array& rhs){
        std::cout << "copy assingmnet operator" << "\n";
        if (&rhs ==  this){
            return *this;
        }
        delete[] data;
        data = new int[10];
        for (int i=0;i<10;i++){
            data[i] = rhs.data[i];
        }

        return *this;
    }

    void printdata(){
        for(int i=0;i<10;i++){
            std::cout << data[i] << std::endl;
        }
    }

    void setdata(int index,int value){
        data[index] = value ;                                 
    }

    private:
    int*data;
};


int main(){
    Array myarray;

    // Array myarray2 = myarray; //for copy constructor 

    Array myarray2;
    myarray2 = myarray;

    myarray.setdata(0,1000);
    myarray.setdata(1,999);
    myarray.setdata(2,979);

    myarray.printdata();
    myarray2.printdata();

}