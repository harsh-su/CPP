/**
 * @file
 * @brief Implementation of [Floyd's Cycle
 * Detection](https://en.wikipedia.org/wiki/Cycle_detection) algorithm
 * @details
 * Given an array of integers containing 'n + 1' integers, where each
 * integer is in the range [1, n] inclusive. If there is only one duplicate
 * number in the input array, this algorithm returns the duplicate number in
 * O(1) space and the time complexity is less than O(n^2) without modifying the
 * original array, otherwise, it returns -1.
 * @author [Swastika Gupta](https://github.com/Swastyy)
 */

#include<cassert>
#include<iostream>
#include<vector>

template <typename T>
int32_t duplicate_num(const std::vector<T> &in_arr,const u_int32_t &n){
    if (n==0 || n==1){
        return -1;
    }

    int32_t tortoise  = in_arr[0];
    int32_t hare = in_arr[0];

    do {
        std::cout << tortoise << hare << std::endl;
        tortoise = in_arr[tortoise];
        hare = in_arr[in_arr[hare]];
    }while(tortoise !=hare);

    tortoise = in_arr[0];

    std:: cout << "found tortoise ! hare " << std::endl;

    while(tortoise != hare){
        
        std::cout << tortoise << hare << std::endl;
    
        tortoise = in_arr[tortoise];
        hare  = in_arr[hare];
    }

    return tortoise;

}

int main(){
    std::vector<u_int32_t> array1 = {3, 4, 8, 5, 9, 1, 2, 6, 7, 4};
    std::cout << "Test 1... ";
    assert(duplicate_num(array1, array1.size()) ==
           4 );  // here the duplicate number is 4
    std::cout << "passed" << std::endl;
}

