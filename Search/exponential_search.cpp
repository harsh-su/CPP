/*Wroking 
 * The algorithm try to search the range where the key should be.
 * If it has been found we do a binary search there.
 * The range of the search grows by exponential every time.
 * If the key is larger than the last element of array, the start of
 * block(block_front) will be equal to the end of block(block_size) and the
 * algorithm return null ponter, every other cases the algoritm return fom the
 * loop.
 * */

/*/** Struzik Search Algorithm(Exponential) -> needs sorted list 
 * * Time Complexity O(log i) where i is the position of search key in the list
 * * Worst Time Complexity O(log i)
 * * Best Time Complexity Ω(1)
 * * Space Complexity O(1)
 * * Auxiliary Space Complexity O(1)
 */

#include<iostream>
#include<string>
#include<assert.h>
#include<math.h>

template <class Type>
inline Type* binary_search(Type* arr,size_t size ,Type key){
    int lower_index(0);
    int upper_index(size-1);

    int middle_index;

    while(lower_index <= upper_index){
        middle_index = std::floor((lower_index+upper_index)/2);
        if(*(arr +middle_index) < key){
            lower_index = ( middle_index +1);
        }else if (*(arr +middle_index) > key){
            upper_index = (middle_index-1);
        }else {
            return (arr + middle_index);
        }
    }
    return nullptr;

}

template<class Type>
Type* struzik_search(Type* array,size_t size,Type key){
    int block_front(0);
    int block_size = size;
    if (block_size == 0 ){
        return 0;
    }

    while (block_front !=block_size)
    {
        if (*(array + block_size-1) < key){
            block_front =block_size;
            (block_size*2 -1 <size) ? (block_size*=2) : block_size = size;
            continue;
        }
    return binary_search<Type>(array+block_front,(block_size-block_front),key);
    } 
    return nullptr;
}
/** Main function */
int main() {
    // TEST CASES
    int* sorted_array = new int[7]{7, 10, 15, 23, 70, 105, 203};
    assert(struzik_search<int>(sorted_array, 7, 0) == nullptr);
    assert(struzik_search<int>(sorted_array, 7, 1000) == nullptr);
    assert(struzik_search<int>(sorted_array, 7, 50) == nullptr);
    assert(struzik_search<int>(sorted_array, 7, 7) == sorted_array);
    // TEST CASES
    delete[] sorted_array;
    return 0;
}