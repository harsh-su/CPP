#include<iostream>

int linear_search(int* arr,int size ,int key){
    for (int i=0;i<size;i++){
        if (arr[i] == key){
            return i;

        }
    }

    return -1;
}

int main()
{
    
}