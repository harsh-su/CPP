/*
Bubble sort algorithm is the bubble sorting algorithm. The most important reason for calling the bubble is that the largest number is thrown at the end of this algorithm. This is all about the logic. In each iteration, the largest number is expired and when iterations are completed, the sorting takes place.

worst case O ( n*n)
Best case O (n)
*/

#include<iostream>
#include <vector>

template <typename T >
auto bubble_sort( std::vector<T> &arr){
    std::vector<T> temp(arr.begin(),arr.end());
    T n = temp.size();
    bool swapped;
    for (int i=0;i<n-1 && (swapped);i++){
        swapped = false;
        for (int j=0;j<n-i-1;j++){
            if (temp[j] > temp[j+1]){
                std::swap(temp[j],temp[j+1]);
                swapped =true;
            }
        }
    }

    arr =temp;
}

template <typename T>
void print_arr(const std::vector<T> &arr){
    for (const auto& item : arr){
        std::cout << item <<" ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int>arr = { 64, 34, 25, 12, 22, 11, 90 };
    bubble_sort(arr);
    print_arr(arr);
}